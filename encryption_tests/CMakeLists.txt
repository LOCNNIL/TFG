cmake_minimum_required(VERSION 3.16.3)

project(Encryption_tests)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)

set(GCC_WARNING_FLAGS 
"-Wall -Wextra -Wfloat-equal \
 -Wno-unused-variable -Werror -Wfatal-errors"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARNING_FLAGS} ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_WARNING_FLAGS}")

set(SOURCES
  ${PROJECT_SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

