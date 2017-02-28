#ifndef _NOAAPRODUCT_H_
#define _NOAAPRODUCT_H_

#include <map>
#include <string>
#include "NOAASubproduct.h"
#include "Types/NOAAProductID.h"

using namespace std;
namespace XRIT {
    class NOAAProduct {
        public:
            int ID;
            string Name;
            map<int, NOAASubproduct> SubProducts;

            NOAAProduct() {}

            NOAAProduct(int id) {
                ID = id;
                Name = "Unknown";
            }

            NOAAProduct(int id, string name) {
                ID = id;
                Name = name;
            }

            NOAAProduct(NOAAProductID::NOAAProductID id, string name) {
                ID = (int)id;
                Name = name;
            }

            NOAAProduct(NOAAProductID::NOAAProductID id, string name, map<int, NOAASubproduct> subProducts) {
                ID = (int)id;
                Name = name;
                SubProducts = subProducts;
            }

            NOAAProduct(int id, string name, map<int, NOAASubproduct> subProducts) {
                ID = id;
                Name = name;
                SubProducts = subProducts;
            }

            NOAASubproduct getSubProduct(int id) {
                if (SubProducts.count(id)) {
                    return SubProducts[id];
                } else {
                    return NOAASubproduct(id, "Unknown");
                }
            }
    }; 
}

#endif