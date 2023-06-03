#!/bin/bash
sudo rm -r ./build
mkdir ./build
cd ./build

cmake .. -D Without_tests:BOOL=$1

#if [ $#==1 ]
#then 
#    cmake .. -D Dont_use_tests:BOOL=$1
#еlse 
#    cmake ..
#fi
make -j

