#ifndef _DCSFILENAMEHEADER_H
#define _DCSFILENAMEHEADER_H

#include <string>
#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct DCSFilenameRecord {
        uint8_t type;
        uint16_t size;
        
        string Filename;
    };
    #pragma pack(pop)

    class DCSFilenameHeader: public XRITBaseHeader {
        public:
            string Filename;
            bool Init = false;
            
            DCSFilenameHeader(){}

            void Define(DCSFilenameRecord data) {
                Type = HeaderType::DCSFileNameRecord;
                Filename = data.Filename;
                Init = true;
            }
    };
}

#endif