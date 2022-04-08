cmake_minimum_required(VERSION 3.21)
project(modelmi)

set(CMAKE_CXX_STANDARD 14)

add_executable(modelmi main.cpp)

set(CMAKE_PREFIX_PATH /Users/shuumichi/Desktop/libtorch )
find_package(Torch REQUIRED)

