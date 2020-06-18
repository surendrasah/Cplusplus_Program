cmake_minimum_required(VERSION 3.13) 
project(VectorMatrix)              
set(CMAKE_CXX_STANDARD 14)            

# Add main.cpp file of project root directory as source file
add_executable(VectorMatrix Main.cpp VectorMatrix.h VectorMatrix.cpp)

