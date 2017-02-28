#ifndef _HEADERSTRUCTUREDHEADER_H
#define _HEADERSTRUCTUREDHEADER_H

#include <string>
#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct HeaderStructuredRecord {
        uint8_t type;
        uint16_t size;
        
        string Data;
    };
    #pragma pack(pop)

    class HeaderStructuredHeader: public XRITBaseHeader {
        public:
            string Data;
            
            HeaderStructuredHeader(){}

            void Define(HeaderStructuredRecord data) {
                Type = HeaderType::HeaderStructuredRecord;
                Data = data.Data;
            }
    };
}

#endif