#ifndef _SEGMENTIDENTIFICATIONRECORD_H_
#define _SEGMENTIDENTIFICATIONRECORD_H_

#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct SegmentIdentificationRecord {
        uint8_t type;
        uint16_t size;

        uint16_t ImageID;
        uint16_t Sequence;
        uint16_t StartColumn;
        uint16_t StartLine;
        uint16_t MaxSegments;
        uint16_t MaxColumns;
        uint16_t MaxRows;

        void Correct() {
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                ImageID = boost::endian::endian_reverse(ImageID);
                Sequence = boost::endian::endian_reverse(Sequence);
                StartColumn = boost::endian::endian_reverse(StartColumn);
                StartLine = boost::endian::endian_reverse(StartLine);
                MaxSegments = boost::endian::endian_reverse(MaxSegments);
                MaxColumns = boost::endian::endian_reverse(MaxColumns);
                MaxRows = boost::endian::endian_reverse(MaxRows);
            }
        }
    };
    #pragma pack(pop)

    class SegmentIdentificationHeader: public XRITBaseHeader {
        public:
            uint16_t ImageID;
            uint16_t Sequence;
            uint16_t StartColumn;
            uint16_t StartLine;
            uint16_t MaxSegments;
            uint16_t MaxColumns;
            uint16_t MaxRows;
            
            SegmentIdentificationHeader(){}

            void Define(SegmentIdentificationRecord data) {
                Type = HeaderType::SegmentIdentificationRecord;
                ImageID = data.ImageID;
                Sequence = data.Sequence;
                StartColumn = data.StartColumn;
                StartLine = data.StartLine;
                MaxSegments = data.MaxSegments;
                MaxRows = data.MaxRows;
            }
    };
}

#endif