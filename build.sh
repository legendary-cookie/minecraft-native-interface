#!/bin/bash

mkdir -pv build/
cd build 
if [[ -f "CMakeCache.txt" ]]; then
	ninja
else
	cmake -GNinja ..
	ninja
fi
