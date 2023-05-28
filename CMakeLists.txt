cmake_minimum_required(VERSION 3.22)
project(iplb)

set(CMAKE_CXX_STANDARD 14)

add_executable(iplb main.cpp conf.cpp conf.h next.cpp next.h util.cpp util.h)
