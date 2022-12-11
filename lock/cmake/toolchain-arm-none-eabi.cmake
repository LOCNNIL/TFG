# CMake toolchain file for building ARM software libs (for RP2040 MCU)

# Processor
set(CMAKE_SYSTEM_PROCESSOR arm)
# this one is important
set(CMAKE_SYSTEM_NAME Generic)
#this one not so much
set(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_STAGING_PREFIX /home/lincoln/TFG/lock)

# specify the cross compiler
set(CMAKE_C_COMPILER   /usr/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++)
set(CMAKE_MAKE_PROGRAM=/usr/bin/make)

set(CMAKE_C_FLAGS="-mcpu=cortex-m0plus -mthumb -O2")
set(CMAKE_CXX_FLAGS="-mcpu=cortex-m0plus -mthumb -O2")

set(CMAKE_EXE_LINKER_FLAGS " --specs=nosys.specs")

set(CMAKE_STRIP /usr/bin/arm-none-eabi-strip)

# where is the target environment 
set(CMAKE_FIND_ROOT_PATH  /usr/arm-none-eabi)

# search for programs in the build host directories
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
