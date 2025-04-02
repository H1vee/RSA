cmake_minimum_required(VERSION 3.30)
project(RSA)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(SOURCES
        source/RSA.cpp
        source/HashFunction.cpp
        source/DigitalSignature.cpp
        source/FileHandler.cpp
        source/Signer.cpp
        source/Verifier.cpp
        source/main.cpp
)
add_executable(RSA ${SOURCES})