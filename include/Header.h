#ifndef _Header_H_
#define _Header_H_

#include <vector>
#include "headers/AncillaryHeader.h"
#include "headers/AnnotationHeader.h"
#include "headers/DCSFilenameHeader.h"
#include "headers/HeaderStructuredHeader.h"
#include "headers/ImageDataFunctionHeader.h"
#include "headers/ImageNavigationHeader.h"
#include "headers/ImageStructureHeader.h"
#include "headers/NOAASpecificHeader.h"
#include "headers/PrimaryHeader.h"
#include "headers/RiceCompressionHeader.h"
#include "headers/SegmentIdentificationHeader.h"
#include "headers/TimestampHeader.h"
#include "headers/XRITBaseHeader.h"
#include "types/CompressionType.h"
#include "NOAAProduct.h"
#include "NOAASubproduct.h"

using namespace std;
namespace XRIT {
    class Header {
        public:
            AncillaryHeader AncillaryHeader;
            AnnotationHeader AnnotationHeader;
            DCSFilenameHeader DCSFilenameHeader;
            HeaderStructuredHeader HeaderStructuredHeader;
            ImageDataFunctionHeader ImageDataFunctionHeader;
            ImageNavigationHeader ImageNavigationHeader;
            ImageStructureHeader ImageStructureHeader;
            NOAASpecificHeader NOAASpecificHeader;
            PrimaryHeader PrimaryHeader;
            RiceCompressionHeader RiceCompressionHeader;
            SegmentIdentificationHeader SegmentIdentificationHeader;
            TimestampHeader TimestampHeader;
            vector<XRITBaseHeader> UnknownHeaders;

            Header() {

            }

            string Filename() {
                if (DCSFilenameHeader.Init) {
                    return DCSFilenameHeader.Filename;
                } else if (AnnotationHeader.Init) {
                    return AnnotationHeader.Filename;
                } else {
                    return "";
                }
            }

            CompressionType::CompressionType Compression() {
                if (NOAASpecificHeader.Init) {
                    return NOAASpecificHeader.Compression;
                } else if (ImageStructureHeader.Init) {
                    return ImageStructureHeader.Compression;
                } else {
                    return CompressionType::NO_COMPRESSION;
                }
            }

            bool IsCompressed() {
                return Compression() != CompressionType::NO_COMPRESSION;
            }

            NOAAProduct Product() {
                if (NOAASpecificHeader.Init) {
                    return NOAASpecificHeader.Product;
                } else {
                    return NOAAProduct(-1);
                }
            }

            NOAASubproduct SubProduct() {
                if (NOAASpecificHeader.Init) {
                    return NOAASpecificHeader.SubProduct;
                } else {
                    return NOAASubproduct(-1);
                }
            }
    };
}

#endif
