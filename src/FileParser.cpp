#include <iostream>
#include "FileParser.h"

using namespace std;
namespace XRIT {
    Header FileParser::GetHeader(vector<uint8_t> data) {
        Header header;
        data.erase(data.begin(), data.begin()+10);
        int maxLength = data.size(); // Initial Guess
        int c = 0;

        while (c < maxLength) {
            uint8_t type = data.at(0);

            uint16_t size = ((uint16_t)data.at(2) << 8) | data.at(1);
            if (Tools.isLittleEndian()) {
                size = (size>>8) | (size<<8);
            }
            
            vector<uint8_t> tmp;
            tmp.insert(tmp.end(), data.begin(), data.begin()+size);

            if (tmp.size() < size) {
                cout << "Not enough data for unpack header: Expected " << size << " got " << tmp.size() << endl;
                break;
            }
            
            switch ((int)type) {
                case HeaderType::PrimaryHeader: {
                    header.PrimaryHeader.RawData = tmp;
                    PrimaryRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.PrimaryHeader.Define(record);
                    maxLength = (uint32_t)record.HeaderLength;
                    break;
                }
                case HeaderType::DCSFileNameRecord: {
                    header.DCSFilenameHeader.RawData = tmp;
                    DCSFilenameRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Filename = Tools.Binary2String(tmp);
                    header.DCSFilenameHeader.Define(record);
                    break;
                }
                case HeaderType::ImageStructureRecord: {
                    header.ImageStructureHeader.RawData = tmp;
                    ImageStructureRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.ImageStructureHeader.Define(record);
                    break;
                }
                case HeaderType::ImageNavigationRecord: {
                    header.ImageNavigationHeader.RawData = tmp;
                    ImageNavigationRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.ImageNavigationHeader.Define(record);
                    break;
                }
                case HeaderType::ImageDataFunctionRecord: {
                    header.ImageDataFunctionHeader.RawData = tmp;
                    ImageDataFunctionRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.ImageDataFunctionHeader.Define(record);
                    break;
                }
                case HeaderType::AnnotationRecord: {
                    header.AnnotationHeader.RawData = tmp;
                    AnnotationRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Filename = Tools.Binary2String(tmp);
                    header.AnnotationHeader.Define(record);
                    break;
                }
                case HeaderType::TimestampRecord: {
                    header.TimestampHeader.RawData = tmp;
                    TimestampRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.TimestampHeader.Define(record);
                    break;
                }
                case HeaderType::AncillaryTextRecord: {
                    header.AncillaryHeader.RawData = tmp;
                    AncillaryText record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.AncillaryHeader.Define(record);
                    break;
                }
                case HeaderType::KeyRecord: {
                    break;
                }
                case HeaderType::SegmentIdentificationRecord: {
                    header.SegmentIdentificationHeader.RawData = tmp;
                    SegmentIdentificationRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.SegmentIdentificationHeader.Define(record);
                    break;
                }
                case HeaderType::NOAASpecificHeader: {
                    header.NOAASpecificHeader.RawData = tmp;
                    NOAASpecificRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.NOAASpecificHeader.Define(record);
                    break;
                }
                case HeaderType::HeaderStructuredRecord: {
                    header.HeaderStructuredHeader.RawData = tmp;
                    HeaderStructuredRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.HeaderStructuredHeader.Define(record);
                    break;
                }
                case HeaderType::RiceCompressionRecord: {
                    header.RiceCompressionHeader.RawData = tmp;
                    RiceCompressionRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.RiceCompressionHeader.Define(record);
                    break;
                }
                default:
                    break;
            }

            c += size;
            data.erase(data.begin(), data.begin()+size);
        }
        return header;
    }
}