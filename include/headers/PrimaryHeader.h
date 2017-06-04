#ifndef _PRIMARYHEADER_H
#define _PRIMARYHEADER_H

#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"
#include "../types/FileTypeCode.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    typedef struct {
        uint8_t type;
        uint16_t size;

        uint8_t FileTypeCode;
        uint32_t HeaderLength;
        uint64_t DataLength;

        void Correct() {
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                FileTypeCode = boost::endian::endian_reverse(FileTypeCode);
                HeaderLength = boost::endian::endian_reverse(HeaderLength);
                DataLength = boost::endian::endian_reverse(DataLength);
            }
        }
    } PrimaryRecord;
    #pragma pack(pop)

    class PrimaryHeader: public XRITBaseHeader {
        public:
            FileTypeCode::FileTypeCode FileType;
            uint32_t HeaderLength;
            uint64_t DataLength;
            
            PrimaryHeader(){}

            void Define(PrimaryRecord data) {
                Type = HeaderType::PrimaryHeader;
                FileType = (FileTypeCode::FileTypeCode)data.FileTypeCode;
                HeaderLength = data.HeaderLength;
                DataLength = data.DataLength;
            }
    };
}

#endif