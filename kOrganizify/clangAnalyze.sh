#!/bin/bash

for file in $(find . -name "*.cpp" -o -name "*.h"); do
    clang-check -analyze "$file"
done > output.log 2>&1
