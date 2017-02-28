# xritlib
This program works with LRIT and HRIT packets from NOAA Geostationary Satellites (GOES-13, GOES-15, GOES-16 and GOES-14). 

### Installation 
Using CMake:
```
git clone https://github.com/luigifreitas/xritlib.git
mkdir build
cd build
cmake ..
make
sudo make install
```

### Usage
``` c++
#include <xrit/lib.h> // Wildcard Header
``` 

### Dependencies 
- [libaec](https://github.com/MathisRosenhauer/libaec)

