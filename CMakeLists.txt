cmake_minimum_required(VERSION 3.14)
project(curves-app)

set(CMAKE_CXX_STANDARD 20)

add_library(curve SHARED
    src/curve/circle.h
    src/curve/circle.cpp
    src/curve/curve.h
    src/curve/ellipse.h
    src/curve/ellipse.cpp
    src/curve/helix.h
    src/curve/helix.cpp
    src/curve/utils.h
    src/curve/utils.cpp
)

add_library(factories SHARED
    src/factories/base_random_curve_factory.h
    src/factories/random_factories.h
    src/factories/random_factories.cpp
)

find_package(OpenMP)

add_executable(curves_App src/main.cpp)

if (OpenMP_CXX_FOUND)
    target_link_libraries(curves_App PUBLIC OpenMP::OpenMP_CXX)
endif()


target_link_libraries(factories PUBLIC curve)

target_link_libraries(curves_App PUBLIC factories)