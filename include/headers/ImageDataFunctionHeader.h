#ifndef _IMAGEDATAFUNCTIONHEADER_H
#define _IMAGEDATAFUNCTIONHEADER_H

#include <string>
#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct ImageDataFunctionRecord {
        uint8_t type;
        uint16_t size;
        
        string Data;
    };
    #pragma pack(pop)

    class ImageDataFunctionHeader: public XRITBaseHeader {
        public:
            string Data;
            
            ImageDataFunctionHeader(){}

            void Define(ImageDataFunctionRecord data) {
                Type = HeaderType::ImageDataFunctionRecord;
                Data = data.Data;
            }
    };
}

#endif