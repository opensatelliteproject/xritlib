#ifndef _XRITBASEHEADER_H_
#define _XRITBASEHEADER_H_

#include <vector>
#include "../Types/HeaderType.h"

using namespace std;
namespace XRIT {
    class XRITBaseHeader {
        public:
            HeaderType::HeaderType Type;
            vector<uint8_t> RawData;

            XRITBaseHeader() {
                Type = HeaderType::Unknown;
            }

            XRITBaseHeader(HeaderType::HeaderType type, vector<uint8_t> rawData) {
                Type = type;
                RawData = rawData;
            }
    };
}

#endif