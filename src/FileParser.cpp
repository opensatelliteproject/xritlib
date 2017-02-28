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
                cout << "Not enough data for unpack header: Expected " << size << " got " << tmp.size() << "\n";
                break;
            }

            //cout << "TYPE: " << (int)type << "\n";
            
            switch ((int)type) {
                case HeaderType::PrimaryHeader: {
                    header.PrimaryHeader.RawData = tmp;
                    PrimaryRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.PrimaryHeader.Define(record);
                    maxLength = (uint32_t)record.HeaderLength;

                    /*cout << "PH FileTypeCode: " << (int)record.FileTypeCode << endl;
                    cout << "PH HeaderLength: " << (uint32_t)record.HeaderLength << endl;
                    cout << "PH DataLength: " << (uint64_t)record.DataLength << endl;*/
                    break;
                }
                case HeaderType::DCSFileNameRecord: {
                    header.DCSFilenameHeader.RawData = tmp;
                    DCSFilenameRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Filename = Tools.Binary2String(tmp);
                    header.DCSFilenameHeader.Define(record);

                    //cout << "DCS Filename: " << (string)record.Filename << endl;
                    break;
                }
                case HeaderType::ImageStructureRecord: {
                    header.ImageStructureHeader.RawData = tmp;
                    ImageStructureRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.ImageStructureHeader.Define(record);

                    /*cout << "BitsPerPixel: " << (int)record.BitsPerPixel << endl;
                    cout << "Columns: " << (uint16_t)record.Columns << endl;
                    cout << "Lines: " << (uint16_t)record.Lines << endl;
                    cout << "Compression: " << (int)record.Compression << endl;*/
                    break;
                }
                case HeaderType::ImageNavigationRecord: {
                    header.ImageNavigationHeader.RawData = tmp;
                    ImageNavigationRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.ImageNavigationHeader.Define(record);

                    /*cout << "ColumnScalingFactor: " << (uint32_t)record.ColumnScalingFactor << endl;
                    cout << "LineScalingFactor: " << (uint32_t)record.LineScalingFactor << endl;
                    cout << "ColumnOffset: " << (uint32_t)record.ColumnOffset << endl;
                    cout << "LineOffset: " << (uint32_t)record.LineOffset << endl;*/
                    break;
                }
                case HeaderType::ImageDataFunctionRecord: {
                    header.ImageDataFunctionHeader.RawData = tmp;
                    ImageDataFunctionRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.ImageDataFunctionHeader.Define(record);

                    //cout << "IDF Data: " << (string)record.Data << endl;
                    break;
                }
                case HeaderType::AnnotationRecord: {
                    header.AnnotationHeader.RawData = tmp;
                    AnnotationRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Filename = Tools.Binary2String(tmp);
                    header.AnnotationHeader.Define(record);

                    //cout << "AR Filename: " << (string)record.Filename << endl;
                    break;
                }
                case HeaderType::TimestampRecord: {
                    header.TimestampHeader.RawData = tmp;
                    TimestampRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.TimestampHeader.Define(record);

                    /*cout << "TS Milissecods: " << (uint32_t)record.Milisseconds << endl;
                    cout << "TS Days: " << (uint16_t)record.Days << endl;*/
                    break;
                }
                case HeaderType::AncillaryTextRecord: {
                    header.AncillaryHeader.RawData = tmp;
                    AncillaryText record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.AncillaryHeader.Define(record);

                    //cout << "AT Data: " << (string)record.Data << endl;
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

                    /*cout << "ImageID: " << (uint16_t)record.ImageID << endl;
                    cout << "Sequence: " << (uint16_t)record.Sequence << endl;
                    cout << "StartColumn: " << (uint16_t)record.StartColumn << endl;
                    cout << "StartLine: " << (uint16_t)record.StartLine << endl;
                    cout << "MaxSegments: " << (uint16_t)record.MaxSegments << endl;
                    cout << "MaxColumns: " << (uint16_t)record.MaxColumns << endl;
                    cout << "MaxRows: " << (uint16_t)record.MaxRows << endl;*/
                    break;
                }
                case HeaderType::NOAASpecificHeader: {
                    header.NOAASpecificHeader.RawData = tmp;
                    NOAASpecificRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.NOAASpecificHeader.Define(record);
                    
                    /*cout << "Signature: " << (string)record.Signature << endl;
                    cout << "Compression: " << (int)record.Compression << endl;
                    cout << "ProductID: " << (uint16_t)record.ProductID << endl;*/
                    break;
                }
                case HeaderType::HeaderStructuredRecord: {
                    header.HeaderStructuredHeader.RawData = tmp;
                    HeaderStructuredRecord record;
                    tmp.erase(tmp.begin(), tmp.begin()+3);
                    record.Data = Tools.Binary2String(tmp);
                    header.HeaderStructuredHeader.Define(record);

                    //cout << "HS Data: " << (string)record.Data << endl;
                    break;
                }
                case HeaderType::RiceCompressionRecord: {
                    header.RiceCompressionHeader.RawData = tmp;
                    RiceCompressionRecord record;
                    memcpy(&record, tmp.data(), tmp.size());
                    record.Correct();
                    header.RiceCompressionHeader.Define(record);

                    /*cout << "Flags: " << (uint16_t)record.Flags << endl;
                    cout << "Pixel: " << (int)record.Pixel << endl;
                    cout << "Line: " << (int)record.Line << endl;*/
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