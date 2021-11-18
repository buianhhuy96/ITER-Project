#!/bin/sh
export LD_LIBRARY_PATH=../lib/Linux/runtime/glnxa64:../lib/Linux/bin/glnxa64:../lib/Linux/sys/os/glnxa64:../lib/Linux/extern/bin/glnxa64

cd "Debug"
make all

cd ..