cmake_minimum_required(VERSION 3.0.0)
project(module_test VERSION 0.1.0)

if(Without_tests)
	message("tests build off")
else()#"" or FALSE => use tests
	message("tests build on")
	add_subdirectory(module_1)
	add_subdirectory(module_2)
endif(Without_tests)

add_executable(mod_test main.cpp)#for main dir

set(Without_tests FALSE CACHE BOOL "Variable for tests" FORCE)


message("text msg")
