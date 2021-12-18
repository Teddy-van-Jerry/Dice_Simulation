#!/bin/sh

# compile_ds_gcc.sh
#
# Compile Dice Simulation Library into object file using g++.
# Object files are in folder 'obj'.
# Warnings are disabled.
#
# Teddy van Jerry
# 2021/12/18

# create dirs
mkdir obj
mkdir obj/ds

# compile object files
g++ -w -c "../src/ds/ds_core.cpp" -std=c++11 -I../ext/reactphysics3d/include -I../include -o "obj/ds/ds_core.o"

echo "Compile DS Finished!\n"
