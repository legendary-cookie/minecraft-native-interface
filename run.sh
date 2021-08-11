#!/bin/bash

echo "WARN: This script assumes minecraft is running and only ONE process with java is running"

PID=$(pidof java)
echo "PID: $PID"

sudo inject $PID _build/out/library/libMinecraft.so