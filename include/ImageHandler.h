#ifndef _IMAGEHANDLER_H_
#define _IMAGEHANDLER_H_

#include <string>
#include <iostream>
#include "Header.h"
#include "Tools.h"

using namespace std;
namespace XRIT {
    class ImageHandler {
        private: 
            Tools Tools;

        public:
            ImageHandler() {}

            void HandleFile(string filename, string outputFolder, Header header);
            void ProcessCompressedFile(vector<uint8_t> file, Header header, string outputFolder);
            void ProcessFile(vector<uint8_t> file, Header header, string outputFolder);
    }; 
}

#endif