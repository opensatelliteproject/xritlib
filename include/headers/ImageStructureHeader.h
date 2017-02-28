#ifndef _IMAGESTRUCTUREHEADER_H
#define _IMAGESTRUCTUREHEADER_H

#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"
#include "../Types/CompressionType.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct ImageStructureRecord {
        uint8_t type;
        uint16_t size;

        uint8_t BitsPerPixel;
        uint16_t Columns;
        uint16_t Lines;
        uint8_t Compression;

        void Correct() {
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                BitsPerPixel = boost::endian::endian_reverse(BitsPerPixel);
                Columns = boost::endian::endian_reverse(Columns);
                Lines = boost::endian::endian_reverse(Lines);
                Compression = boost::endian::endian_reverse(Compression);
            }
        }
    };
    #pragma pack(pop)

    class ImageStructureHeader: public XRITBaseHeader {
        public:
            uint8_t BitsPerPixel;
            uint16_t Columns;
            uint16_t Lines;
            CompressionType::CompressionType Compression;
            bool Init = false;
            
            ImageStructureHeader(){}
            
            void Define(ImageStructureRecord data) {
                Type = HeaderType::ImageStructureRecord;
                BitsPerPixel = data.BitsPerPixel;
                Columns = data.Columns;
                Lines = data.Lines;
                Compression = (CompressionType::CompressionType)data.Compression;
                Init = true;
            }
    };
}

#endif