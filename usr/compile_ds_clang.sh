#!/bin/sh

# compile_ds_clang.sh
#
# Compile Dice Simulation Library into object file using clang++.
# Object files are in folder 'obj'.
# Warnings are disabled.
#
# Teddy van Jerry
# 2021/12/18

# create dirs
mkdir obj
mkdir obj/ds

# compile object files
clang++ -w -c -o3 "../src/ds/ds_core.cpp" -std=c++11 -I../ext/reactphysics3d/include -I../include -o "obj/ds/ds_core.o"

echo "Compile DS Finished!\n"
