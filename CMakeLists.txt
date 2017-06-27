cmake_minimum_required(VERSION 3.7)
project(MatrixCpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        com/giappi/lang/Matrix.cpp
        com/giappi/lang/Matrix.h
        com/giappi/lang/SquareMatrix.cpp
        com/giappi/lang/SquareMatrix.h
        Main.cpp)

add_executable(MatrixCpp ${SOURCE_FILES})