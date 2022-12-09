# CMake toolchain file for building ARM software libs (for RP2040 MCU)

# Processor
SET(CMAKE_SYSTEM_PROCESSOR arm)
# this one is important
SET(CMAKE_SYSTEM_NAME Generic)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

# (OPTIONAL) specify some CPU flags
SET(cpu_flags "-mcpu=cortex-m0plus -mthumb")

# specify the cross compiler
SET(CMAKE_C_COMPILER   /usr/bin/arm-none-eabi-gcc ${cpu_flags})
SET(CMAKE_CXX_COMPILER /usr/bin/arm-none-eabi-g++ ${cpu_flags})

SET(CMAKE_STRIP /usr/bin/arm-none-eabi-strip)

# where is the target environment 
SET(CMAKE_FIND_ROOT_PATH  /usr/arm-none-eabi)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)