#ifndef _Header_H_
#define _Header_H_

#include <vector>
#include "Headers/AncillaryHeader.h"
#include "Headers/AnnotationHeader.h"
#include "Headers/DCSFilenameHeader.h"
#include "Headers/HeaderStructuredHeader.h"
#include "Headers/ImageDataFunctionHeader.h"
#include "Headers/ImageNavigationHeader.h"
#include "Headers/ImageStructureHeader.h"
#include "Headers/NOAASpecificHeader.h"
#include "Headers/PrimaryHeader.h"
#include "Headers/RiceCompressionHeader.h"
#include "Headers/SegmentIdentificationHeader.h"
#include "Headers/TimestampHeader.h"
#include "Headers/XRITBaseHeader.h"
#include "Types/CompressionType.h"
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