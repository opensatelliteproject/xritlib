#ifndef _PRESETS_H_
#define _PRESETS_H_

#include <map>
#include <string>
#include "NOAAProduct.h"
#include "Types/NOAAProductID.h"

using namespace std;
namespace XRIT {
    class Presets {
        private:
        public:
            map<int, NOAAProduct> noaaProducts;

            Presets() {
                map<int, NOAASubproduct> tmp;
                noaaProducts[(int)NOAAProductID::NOAA_TEXT] = NOAAProduct(NOAAProductID::NOAA_TEXT, "NOAA Text");

                tmp = {
                    { 0, NOAASubproduct(0, "None") },
                    { 1, NOAASubproduct(1, "Infrared Full Disk") },
                    { 3, NOAASubproduct(3, "Visible Full Disk") }
                };
                
                noaaProducts[(int)NOAAProductID::OTHER_SATELLITES_1] = NOAAProduct(NOAAProductID::OTHER_SATELLITES_1, "Other Satellites", tmp);

                tmp = {
                    { 0, NOAASubproduct(0, "None") },
                    { 1, NOAASubproduct(1, "Infrared Full Disk") },
                    { 3, NOAASubproduct(3, "Visible Full Disk") }
                };

                noaaProducts[(int)NOAAProductID::OTHER_SATELLITES_2] = NOAAProduct(NOAAProductID::OTHER_SATELLITES_2, "Other Satellites", tmp);

                noaaProducts[(int)NOAAProductID::WEATHER_DATA] = NOAAProduct(NOAAProductID::WEATHER_DATA, "Weather Data");

                noaaProducts[(int)NOAAProductID::DCS] = NOAAProduct(NOAAProductID::DCS, "DCS");

                tmp = { 
                    { (int)ScannerSubProduct::NONE,                         NOAASubproduct(ScannerSubProduct::NONE,                          "None") },
                    { (int)ScannerSubProduct::INFRARED_FULLDISK,            NOAASubproduct(ScannerSubProduct::INFRARED_FULLDISK,             "Infrared Full Disk") },
                    { (int)ScannerSubProduct::INFRARED_NORTHERN,            NOAASubproduct(ScannerSubProduct::INFRARED_NORTHERN,             "Infrared Northern Hemisphere") },
                    { (int)ScannerSubProduct::INFRARED_SOUTHERN,            NOAASubproduct(ScannerSubProduct::INFRARED_SOUTHERN,             "Infrared Southern Hemisphere") },
                    { (int)ScannerSubProduct::INFRARED_UNITEDSTATES,        NOAASubproduct(ScannerSubProduct::INFRARED_UNITEDSTATES,         "Infrared United States") },
                    { (int)ScannerSubProduct::INFRARED_AREA_OF_INTEREST,    NOAASubproduct(ScannerSubProduct::INFRARED_AREA_OF_INTEREST,     "Infrared Area of Interest") },
                    { (int)ScannerSubProduct::VISIBLE_FULLDISK,             NOAASubproduct(ScannerSubProduct::VISIBLE_FULLDISK,              "Visible Full Disk") },
                    { (int)ScannerSubProduct::VISIBLE_NORTHERN,             NOAASubproduct(ScannerSubProduct::VISIBLE_NORTHERN,              "Visible Northern Hemisphere") },
                    { (int)ScannerSubProduct::VISIBLE_SOUTHERN,             NOAASubproduct(ScannerSubProduct::VISIBLE_SOUTHERN,              "Visible Southern Hemisphere") },
                    { (int)ScannerSubProduct::VISIBLE_UNITEDSTATES,         NOAASubproduct(ScannerSubProduct::VISIBLE_UNITEDSTATES,          "Visible United States") },
                    { (int)ScannerSubProduct::VISIBLE_AREA_OF_INTEREST,     NOAASubproduct(ScannerSubProduct::VISIBLE_AREA_OF_INTEREST,      "Visible Area of Interest") },
                    { (int)ScannerSubProduct::WATERVAPOUR_FULLDISK,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_FULLDISK,          "Water Vapour Full Disk") },
                    { (int)ScannerSubProduct::WATERVAPOUR_NORTHERN,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_NORTHERN,          "Water Vapour Northern Hemisphere") },
                    { (int)ScannerSubProduct::WATERVAPOUR_SOUTHERN,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_SOUTHERN,          "Water Vapour Southern Hemisphere") },
                    { (int)ScannerSubProduct::WATERVAPOUR_UNITEDSTATES,     NOAASubproduct(ScannerSubProduct::WATERVAPOUR_UNITEDSTATES,      "Water Vapour United States") },
                    { (int)ScannerSubProduct::WATERVAPOUR_AREA_OF_INTEREST, NOAASubproduct(ScannerSubProduct::WATERVAPOUR_AREA_OF_INTEREST,  "Water Vapour Area of Interest") }
                };

                noaaProducts[(int)NOAAProductID::SCANNER_DATA_1] = NOAAProduct(NOAAProductID::SCANNER_DATA_1, "Scanner Image", tmp);

                tmp = { 
                    { (int)ScannerSubProduct::NONE,                         NOAASubproduct(ScannerSubProduct::NONE,                          "None") },
                    { (int)ScannerSubProduct::INFRARED_FULLDISK,            NOAASubproduct(ScannerSubProduct::INFRARED_FULLDISK,             "Infrared Full Disk") },
                    { (int)ScannerSubProduct::INFRARED_NORTHERN,            NOAASubproduct(ScannerSubProduct::INFRARED_NORTHERN,             "Infrared Northern Hemisphere") },
                    { (int)ScannerSubProduct::INFRARED_SOUTHERN,            NOAASubproduct(ScannerSubProduct::INFRARED_SOUTHERN,             "Infrared Southern Hemisphere") },
                    { (int)ScannerSubProduct::INFRARED_UNITEDSTATES,        NOAASubproduct(ScannerSubProduct::INFRARED_UNITEDSTATES,         "Infrared United States") },
                    { (int)ScannerSubProduct::INFRARED_AREA_OF_INTEREST,    NOAASubproduct(ScannerSubProduct::INFRARED_AREA_OF_INTEREST,     "Infrared Area of Interest") },
                    { (int)ScannerSubProduct::VISIBLE_FULLDISK,             NOAASubproduct(ScannerSubProduct::VISIBLE_FULLDISK,              "Visible Full Disk") },
                    { (int)ScannerSubProduct::VISIBLE_NORTHERN,             NOAASubproduct(ScannerSubProduct::VISIBLE_NORTHERN,              "Visible Northern Hemisphere") },
                    { (int)ScannerSubProduct::VISIBLE_SOUTHERN,             NOAASubproduct(ScannerSubProduct::VISIBLE_SOUTHERN,              "Visible Southern Hemisphere") },
                    { (int)ScannerSubProduct::VISIBLE_UNITEDSTATES,         NOAASubproduct(ScannerSubProduct::VISIBLE_UNITEDSTATES,          "Visible United States") },
                    { (int)ScannerSubProduct::VISIBLE_AREA_OF_INTEREST,     NOAASubproduct(ScannerSubProduct::VISIBLE_AREA_OF_INTEREST,      "Visible Area of Interest") },
                    { (int)ScannerSubProduct::WATERVAPOUR_FULLDISK,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_FULLDISK,          "Water Vapour Full Disk") },
                    { (int)ScannerSubProduct::WATERVAPOUR_NORTHERN,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_NORTHERN,          "Water Vapour Northern Hemisphere") },
                    { (int)ScannerSubProduct::WATERVAPOUR_SOUTHERN,         NOAASubproduct(ScannerSubProduct::WATERVAPOUR_SOUTHERN,          "Water Vapour Southern Hemisphere") },
                    { (int)ScannerSubProduct::WATERVAPOUR_UNITEDSTATES,     NOAASubproduct(ScannerSubProduct::WATERVAPOUR_UNITEDSTATES,      "Water Vapour United States") },
                    { (int)ScannerSubProduct::WATERVAPOUR_AREA_OF_INTEREST, NOAASubproduct(ScannerSubProduct::WATERVAPOUR_AREA_OF_INTEREST,  "Water Vapour Area of Interest") }
                };

                noaaProducts[(int)NOAAProductID::SCANNER_DATA_2] = NOAAProduct(NOAAProductID::SCANNER_DATA_2, "Scanner Image", tmp);

                noaaProducts[(int)NOAAProductID::EMWIN] = NOAAProduct(NOAAProductID::EMWIN, "EMWIN");
            }

            NOAAProduct GetProductById(int productId) {
                if (noaaProducts.count(productId)) {
                    return noaaProducts.at(productId);
                } else {
                    return NOAAProduct(productId);
                }
            }
    }; 
}

#endif