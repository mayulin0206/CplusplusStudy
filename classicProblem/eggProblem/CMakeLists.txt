cmake_minimum_required (VERSION 2.8)
set(CMAKE_CXX_FLAGS "-fPIC --std=c++11") 
project (hello)
add_executable(egg egg.cc)