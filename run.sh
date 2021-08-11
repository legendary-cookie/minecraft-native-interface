#!/bin/bash
PID=$(pidof java)
echo "PID: $PID"

if [[ -f "_build/out/library/libMinecraft.so" ]]; then
    inject $PID _build/out/library/libMinecraft.so
else
    echo "Building library"
    ./build.sh
fi
