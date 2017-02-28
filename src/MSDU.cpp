#include <iostream>
#include "MSDU.h"

using namespace std;
namespace XRIT {
    void MSDU::addDataBytes(vector<uint8_t> data) {
        /*cout << "New Data: " << data.size() << "\n" << 
                "Old Data: " << Data.size()  << "\n" << 
                "PacketLength: " << PacketLength << endl;*/

        if (data.size() + Data.size() > PacketLength + 2) {
            cout << "(MSDU) Overflow in MSDU!\n";
        }
        Data.insert(Data.end(), data.begin(), data.end());
        if (Data.size() > PacketLength + 2) {
            Data.erase(Data.begin()+(PacketLength+2), data.end());
        }
    }

    void MSDU::parseMSDU(vector<uint8_t> data) {
        uint16_t o = ((uint16_t)data.at(1) << 8) | data.at(0);
        if (Tools().isLittleEndian()) {
            o = (o>>8) | (o<<8);
        }
       
        this->Version = (o & 0xE000) >> 13;
        this->Type = (o & 0x1000) >> 12;
        this->SecondHeader = ((o & 0x800) >> 11) > 0;
        this->APID = o & 0x7FF;

        o = ((uint16_t)data.at(3) << 8) | data.at(2);
        if (Tools().isLittleEndian()) {
            o = (o>>8) | (o<<8);
        }

        this->Sequence = (SequenceType::SequenceType)((o & 0xC000) >> 14);
        this->PacketNumber = (o & 0x3FFF);
        
        o = ((uint16_t)data.at(5) << 8) | data.at(4);
        if (Tools().isLittleEndian()) {
            o = (o>>8) | (o<<8);
        }
        
        this->PacketLength = o - 1;

        data.erase(data.begin(), data.begin()+6);
        if (data.size() > this->PacketLength + 2) {
            this->RemainingData.insert(this->RemainingData.end(), data.begin()+(this->PacketLength+2), data.end());
            data.erase(data.begin()+((this->PacketLength + 2)), data.end());
        } else {
            this->RemainingData.clear();
        }

        this->Data.insert(this->Data.end(), data.begin(), data.end());
        this->FrameLost = false;
        
        /*cout << "this->Version: " << this->Version << "\n" << 
                  "this->Type: " << this->Type << "\n" << 
                  "this->SecondHeader: " << this->SecondHeader << "\n" << 
                  "this->APID: " << this->APID << "\n" <<
                  "this->Sequence: " << this->Sequence << "\n" << 
                  "this->PacketNumber: " << this->PacketNumber << "\n" << 
                  "this->PacketLength: " << this->PacketLength << "\n" <<
                  "this->RemainingData: " << this->RemainingData.size() << "\n" << 
                  "this->Data: " << this->Data.size() << "\n";*/
   }
}