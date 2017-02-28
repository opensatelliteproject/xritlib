#include "ImageHandler.h"

using namespace std;
namespace XRIT {
    void ImageHandler::HandleFile(string filename, string outputFolder, Header header) {
        vector<uint8_t> f = Tools.ReadAllBytes(filename);
        if ((int)f.at(0) == 0) {       
            f.erase(f.begin(), f.begin()+(int)header.PrimaryHeader.HeaderLength);
            ProcessFile(f, header, outputFolder);
        } else {
            //wm->Log("Expected header type 0 for first header. Got " + to_string((int)f.at(0)) + ".", 3);
        }
    }

    void ImageHandler::ProcessFile(vector<uint8_t> file, Header header, string outputFolder) {
        uint16_t width = (uint16_t)header.ImageStructureHeader.Columns;
        uint16_t height = (uint16_t)header.ImageStructureHeader.Lines;
        int bitsPerPixel = (int)header.ImageStructureHeader.BitsPerPixel;
        int bytesToRead = (width * height);

        string outName = header.Filename();
        outName.replace(outName.find(".lrit"), 6,  ".png");
        outName = Tools.Combine(outputFolder, outName);

        if (header.NOAASpecificHeader.Compression != CompressionType::NO_COMPRESSION && header.NOAASpecificHeader.Compression != CompressionType::LRIT_RICE) {
            //wm->Log("File is Compressed. Proceeding...", 4);
            ProcessCompressedFile(file, header, outputFolder);
            return;
        }

        if (bitsPerPixel != 8 && bitsPerPixel != 1) {
            //wm->Log("Unsupported bits per pixel " + to_string(bitsPerPixel), 3);
            return;
        }

        FILE *pFp = fopen(outName.c_str(), "wb");
        unsigned char * start = file.data();

        if (pFp) {
            if(bitsPerPixel == 1) {
                bytesToRead /= 8;
                fprintf(pFp, "P4\n%d\n%d\n%d\n", width, height, 1);
            } else {
                fprintf(pFp, "P5\n%d\n%d\n%d\n", width, height, 255);
            }
            
            for (int i = 0; i < bytesToRead; i++) {
                putc(start[i], pFp);
            }
            fclose(pFp);
        }
    }

    void ImageHandler::ProcessCompressedFile(vector<uint8_t> file, Header header, string outputFolder) {
        /*if (header.NOAASpecificHeader.Compression == CompressionType.GIF) {
            string outName = header.Filename.Replace(".lrit", ".gif");
            outName = Path.Combine(outputFolder, outName);
            var file2 = File.OpenWrite(outName);

            byte[] buffer = new Byte[1024];
            int bytesRead;

            while ((bytesRead = file.Read(buffer, 0, 1024)) > 0) {
                file2.Write(buffer, 0, bytesRead);
            }

            file2.Close();
        } else if (header.NOAASpecificHeader.Compression == CompressionType.JPEG) {
            string outName = header.Filename.Replace(".lrit", ".jpg");
            outName = Path.Combine(outputFolder, outName);
            var file2 = File.OpenWrite(outName);

            byte[] buffer = new Byte[1024];
            int bytesRead;

            while ((bytesRead = file.Read(buffer, 0, 1024)) > 0) {
                file2.Write(buffer, 0, bytesRead);
            }

            file2.Close();
        } else {
            throw new Exception(string.Format("Unknown Compression type: {0}", header.NOAASpecificHeader.Compression.ToString()));
        }*/
    }
}
