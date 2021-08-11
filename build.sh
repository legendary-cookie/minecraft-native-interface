#!/bin/bash

mkdir -pv _build/
cd _build 
if [[ -f "CMakeCache.txt" ]]; then
	ninja
else
	cmake -GNinja ..
	ninja
fi
