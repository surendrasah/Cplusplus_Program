cmake_minimum_required(VERSION 3.13) 
project(Car_Simulation)              
set(CMAKE_CXX_STANDARD 14)            

# Add main.cpp file of project root directory as source file
add_executable(Car_Simulation Car_Simulation.cpp Car_Sim_Eval.h Car_Sim_Eval.cpp pch.h pch.cpp)


# Add executable target with source files listed in SOURCE_FILES variable
#add_executable(Car_Simulation myapp)