LDFLAGS=$(shell pkg-config --libs openssl) -pthread -ldl
CFLAGS=-O2 -std=c++14 -stdlib=libc++ -fuse-ld=lld-5.0 -flto=thin

all:
	$(CXX) $(CFLAGS) openssl.cpp $(LDFLAGS) -o openssl-test
