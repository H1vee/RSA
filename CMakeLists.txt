cmake_minimum_required(VERSION 3.30)
project(RSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(RSA source/main.cpp
        include/RSA.h
        source/RSA.cpp
        include/HashFunction.h
        source/HashFunction.cpp)
