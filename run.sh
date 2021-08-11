#!/bin/bash

echo "WARN: This script assumes minecraft is running and only ONE process with java is running"

PID=$(pidof java)
echo "PID: $PID"

inject $PID build/out/library/libMinecraft.so