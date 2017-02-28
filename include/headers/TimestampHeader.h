#ifndef _TIMESTAMPHEADER_H
#define _TIMESTAMPHEADER_H

#include <cstdint>
#include <cstring>
#include <ctime>
#include "XRITBaseHeader.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct TimestampRecord {
        uint8_t type;
        uint16_t size;

        uint16_t Days;
        uint32_t Milisseconds;

        time_t getDateTime() {
            /*DateTime t = new DateTime(1958, 1, 1);
            t.AddDays(Days);
            t.AddMilliseconds(Milisseconds);*/
            time_t time = 0;
            return time;
        }

        void Correct() {
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                Days = boost::endian::endian_reverse(Days);
                Milisseconds = boost::endian::endian_reverse(Milisseconds);
            }
        }
    };
    #pragma pack(pop)

    class TimestampHeader: public XRITBaseHeader {
        public:
            time_t DateTime;
            
            TimestampHeader(){}

            void Define(TimestampRecord data) {
                Type = HeaderType::TimestampRecord;
                DateTime = data.getDateTime();
            }
    };
}

#endif