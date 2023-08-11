# CAD-Exchanger-Curves
## How to run
1) [Install CMake](https://cmake.org/install/)
2) Make sure that your compiler supports OpenMP and C++17 or higher
3) Open console
```
git clone https://github.com/DanSprat/CAD-Exchanger-Curves.git
cd CAD-Exchanger-Curves
mkdir build & cd build
# find in cmake --help
cmake -G "{your generator}" ..
cmake --build . --config Release --target curves_App
./curves_App
```
