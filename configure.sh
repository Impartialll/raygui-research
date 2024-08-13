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
if [[ "$OSTYPE" == "darwin"* ]]; then
gcc -o raygui-4.0/raygui.so raygui-4.0/src/raygui.c \
  -shared -fpic -DRAYGUI_IMPLEMENTATION -framework \
  OpenGL -lm -lpthread -ldl $(pkg-config --libs --cflags raylib)
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
gcc -o raygui.so src/raygui.c -shared -fpic -DRAYGUI_IMPLEMENTATION \
  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
fi

# Copy header
cp raygui-4.0/src/raygui.h .

# Copy shared lib
cp raygui-4.0/raygui.so .

# Remove after compilation
rm -rf raygui-4.0
