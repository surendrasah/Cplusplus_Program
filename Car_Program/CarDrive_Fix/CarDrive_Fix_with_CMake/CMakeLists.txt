cmake_minimum_required(VERSION 3.13) 
project(CarDrive_Fix)              
set(CMAKE_CXX_STANDARD 14)            

# Add main.cpp file of project root directory as source file
add_executable(CarDrive_Fix Main.cpp Car.h Car.cpp)

