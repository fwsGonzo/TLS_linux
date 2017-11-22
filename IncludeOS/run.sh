#!/bin/bash
mkdir -p build
pushd build
cmake ..
make -j4
popd
# might have to flush device to remove stuck TAP
sudo ip addr flush dev bridge43
sudo mknod /dev/net/tap c 10 200
sudo ./build/linux_botan
