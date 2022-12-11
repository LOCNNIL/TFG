cmake_minimum_required(VERSION 3.22)

# Pull in PICO SDK (must be before project)
include(cmake/pico_sdk_import.cmake)
include(cmake/update_git_submodules.cmake)

project(crypto_lock C CXX ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)


set(GCC_WARNING_FLAGS 
"-Wall -Wextra -Wfloat-equal -Werror\
 -Wno-unused-variable -Wfatal-errors"
)

set(GCC_COMPILE_OPTIONS 
# "-fexceptions -frtti"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_OPTIONS} ${GCC_WARNING_FLAGS} ")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COMPILE_OPTIONS} ${GCC_WARNING_FLAGS} ")

message("CXX flags: ${CMAKE_CXX_FLAGS}")
message("C flags: ${CMAKE_C_FLAGS}")
message("ASM flags: ${CMAKE_ASM_FLAGS}")

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#initialize the SDK
pico_sdk_init()

include(cmake/example_auto_set_url.cmake)


if (TARGET tinyusb_device)

    set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/uart/uart.cpp
    ${PROJECT_SOURCE_DIR}/src/protocol/protocol.cpp
    )

    add_executable(${PROJECT_NAME} ${SOURCES})

    target_include_directories(${PROJECT_NAME} 
        PUBLIC ${PROJECT_SOURCE_DIR}/include/
        PUBLIC ${PROJECT_SOURCE_DIR}/include/uart
        PUBLIC ${PROJECT_SOURCE_DIR}/include/protocol
        # PUBLIC ${PROJECT_SOURCE_DIR}/include/mbedtls
        # PUBLIC ${PROJECT_SOURCE_DIR}/include/psa
    )

    # Pull in our pico_stdlib which pulls in com
    target_link_libraries(${PROJECT_NAME} 
        pico_stdlib 
        pico_stdio 
        hardware_uart 
        hardware_irq
        # libmbedcrypto
    )

    # enable usb output, disable uart output
    pico_enable_stdio_usb(${PROJECT_NAME} 1)
    pico_enable_stdio_uart(${PROJECT_NAME} 0)

    # Create map/bin/hex file etc.
    pico_add_extra_outputs(${PROJECT_NAME})

    # add url via pico_set_program_url
    example_auto_set_url(${PROJECT_NAME})

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in
    the SDK")

endif()
