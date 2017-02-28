#ifndef _ANNOTATIONHEADER_H
#define _ANNOTATIONHEADER_H

#include <string>
#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct AnnotationRecord {
        uint8_t type;
        uint16_t size;
        
        string Filename;
    };
    #pragma pack(pop)

    class AnnotationHeader: public XRITBaseHeader {
        public:
            string Filename;
            bool Init = false;

            AnnotationHeader() {}

            void Define(AnnotationRecord data) {
                Type = HeaderType::AnnotationRecord;
                Filename = data.Filename;
                Init = true;
            }
    };
}

#endif