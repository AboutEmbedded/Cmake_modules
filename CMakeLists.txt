cmake_minimum_required(VERSION 3.0.0)
project(module_test VERSION 0.1.0)


add_subdirectory(module_1)
add_subdirectory(module_2)

add_executable(mod_test main.cpp)#for main dir

