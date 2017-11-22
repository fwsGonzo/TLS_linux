cmake_minimum_required(VERSION 2.8.9)
if (NOT DEFINED ENV{INCLUDEOS_PREFIX})
  set(ENV{INCLUDEOS_PREFIX} /usr/local)
endif()
project (service C CXX)

# Human-readable name of your service
set(SERVICE_NAME "Linux botan test")

# Name of your service binary
set(BINARY       "linux_botan")

# Source files to be linked with OS library parts to form bootable image
set(SOURCES
  service.cpp
  http.cpp
  )

include_directories(/usr/local/botan/include)

set(EXTRA_LIBS /usr/local/botan/lib/libbotan-2.a)

include($ENV{INCLUDEOS_PREFIX}/includeos/linux.service.cmake)
