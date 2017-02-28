#ifndef _TEXTHANDLER_H_
#define _TEXTHANDLER_H_

#include <string>
#include <iostream>
#include "Header.h"
#include "Tools.h"

using namespace std;
namespace XRIT {
    class TextHandler {
        private: 
            Tools Tools;

        public:
            TextHandler() {}

            void HandleFile(string filename, string outputFolder, Header header);
            void ProcessFile(vector<uint8_t> file, string outputFolder, Header header);
    }; 
}

#endif