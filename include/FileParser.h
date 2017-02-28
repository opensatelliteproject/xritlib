#ifndef _FILEPARSER_H_
#define _FILEPARSER_H_

#include <vector>
#include "Headers/XRitBaseHeader.h"
#include "Header.h"
#include "Tools.h"

using namespace std;
namespace XRIT {
    class FileParser {
        private:
            Tools Tools;

        public:
            Header GetHeader(vector<uint8_t> data);
    };
}

#endif