#!/bin/bash
git submodule update --init --recursive
pushd botan
#./configure.py --amalgamation --prefix=/usr/local/botan --cc=clang --cc-abi-flags="-std=c++14 -stdlib=libc++ -march=native -fuse-ld=lld-5.0 -flto=thin -O2"
./configure.py --amalgamation --prefix=/usr/local/botan --cc=clang --cc-abi-flags="-std=c++14 -stdlib=libc++ -march=native -O2"
make -j32
sudo make install
popd
