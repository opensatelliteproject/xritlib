#ifndef _NOAASPECIFICHEADER_H
#define _NOAASPECIFICHEADER_H

#include <cstdint>
#include <cstring>
#include "XRITBaseHeader.h"
#include "../Types/CompressionType.h"
#include "../NOAAProduct.h"
#include "../NOAASubproduct.h"
#include "../Presets.h"
#include "../Tools.h"

using namespace std;
namespace XRIT {
    #pragma pack(push, 1)
    struct NOAASpecificRecord {
        uint8_t type;
        uint16_t size;

        char Signature[4];
        uint16_t ProductID;
        uint16_t ProductSubID;
        uint16_t Parameter;
        uint8_t Compression;

        void Correct() {   
            if (Tools().isLittleEndian()) {
                type = boost::endian::endian_reverse(type);
                size = boost::endian::endian_reverse(size);
                ProductID = boost::endian::endian_reverse(ProductID);
                ProductSubID = boost::endian::endian_reverse(ProductSubID);
                Parameter = boost::endian::endian_reverse(Parameter);
                Compression = boost::endian::endian_reverse(Compression);
            }
        }
    };
    #pragma pack(pop)

    class NOAASpecificHeader: public XRITBaseHeader {
        public:
            string Signature;
            NOAAProduct Product;
            NOAASubproduct SubProduct;
            uint16_t Parameter;
            CompressionType::CompressionType Compression;
            Presets Presets;
            bool Init = false;
            
            NOAASpecificHeader(){}

            void Define(NOAASpecificRecord data) {
                Type = HeaderType::NOAASpecificHeader;
                Signature = data.Signature;
                Product = Presets.GetProductById(data.ProductID); 
                SubProduct = Product.getSubProduct(data.ProductSubID);
                Parameter = data.Parameter;
                Compression = (CompressionType::CompressionType)data.Compression;
                Init = true;
            }
    };
}

#endif