#ifndef _RICECOMPRESSIONHEADER_H
#define _RICECOMPRESSIONHEADER_H

#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct RiceCompressionRecord {
        uint8_t type;
        uint16_t size;

        uint16_t Flags;
        uint8_t Pixel;
        uint8_t Line;

        void Correct() {
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                Flags = boost::endian::endian_reverse(Flags);
                Pixel = boost::endian::endian_reverse(Pixel);
                Line = boost::endian::endian_reverse(Line);
            }
        }
    };
    #pragma pack(pop)

    class RiceCompressionHeader: public XRITBaseHeader {
        public:
            uint16_t Flags;
            uint8_t Pixel;
            uint8_t Line;
            
            RiceCompressionHeader(){}

            void Define(RiceCompressionRecord data) {
                Type = HeaderType::RiceCompressionRecord;
                Flags = data.Flags;
                Pixel = data.Pixel;
                Line = data.Line;
            }
    };
}

#endif