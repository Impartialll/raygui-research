#!/bin/bash

# Exit on error
set -e

# Clone raylib 4.0
wget https://github.com/raysan5/raygui/archive/refs/tags/4.0.zip

# Unzip
unzip 4.0.zip

# Remove zip file
rm -f 4.0.zip

# Copy .h to .c
cp raygui-4.0/src/raygui.h raygui-4.0/src/raygui.c

# Compile raygui
gcc -o raygui-4.0/raygui.so raygui-4.0/src/raygui.c \
  -shared -fpic -DRAYGUI_IMPLEMENTATION -framework \
  OpenGL -lm -lpthread -ldl $(pkg-config --libs --cflags raylib)

# Copy header
cp raygui-4.0/src/raygui.h .

# Copy shared lib
cp raygui-4.0/raygui.so .

# Remove after compilation
rm -rf raygui-4.0
