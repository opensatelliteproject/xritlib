#ifndef _MSDU_H_
#define _MSDU_H_

#include <map>
#include <vector>
#include "Types/SequenceType.h"
#include "Tools.h"

using namespace std;
namespace XRIT {
    class MSDU {
        private:
            uint16_t CRC() {
                vector<uint8_t> data = Data;
                data.erase(data.begin(), data.end()-2);
                uint16_t o = ((uint16_t)data.at(1) << 8) | data.at(0);
                if (Tools().isLittleEndian()) {
                    o = (o>>8) | (o<<8);
                }
                return o;
            }

        public:
            bool FrameLost = false;
            int Version;
            int SHF;
            int APID;
            int Type;
            bool SecondHeader;
            SequenceType::SequenceType Sequence;
            int PacketNumber;
            int PacketLength;
            vector<uint8_t> Data;
            vector<uint8_t> RemainingData;

            void addDataBytes(vector<uint8_t> data);
            void parseMSDU(vector<uint8_t> data);
            MSDU parseMSDU(uint8_t data);

            MSDU() { }

            bool Full() { 
                return Data.size() == PacketLength + 2;
            }

            bool Valid() {
                vector<uint8_t> data = Data;
                data.erase(data.end()-2, data.end());

                uint8_t lsb = 0xFF, msb = 0xFF, x;
                for(uint8_t b: data) {
                    x = (uint8_t)(b ^ msb);
                    x ^= (uint8_t)(x >> 4);
                    msb = (uint8_t)(lsb ^ (x >> 3) ^ (x << 4));
                    lsb = (uint8_t)(x ^ (x << 5));
                }
                return ((((int)msb) << 8) + lsb) == CRC();
            }

            bool FillPacket() {
                return APID == 2047;
            }            
    };
}

#endif