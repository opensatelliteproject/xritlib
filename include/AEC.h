#ifndef _AEC_H_
#define _AEC_H_

#include <vector>
extern "C" {
    #include <szlib.h>
}

using namespace std;
namespace XRIT {
    class AEC {
        private:    
        public:
            int ALLOW_K13_OPTION_MASK = 1;
            int CHIP_OPTION_MASK      = 2; 
            int EC_OPTION_MASK        = 4;
            int LSB_OPTION_MASK       = 8;
            int MSB_OPTION_MASK       = 16;
            int NN_OPTION_MASK        = 32;
            int RAW_OPTION_MASK       = 128;

            int Decompress(char *input, char *output, size_t inputLength, size_t outputLength, int bitsPerPixel, int pixelsPerBlock, int pixelsPerScanline, int mask);
    };
}

#endif