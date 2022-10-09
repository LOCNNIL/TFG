cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

project(gate C CXX ASM)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#initialize the SDK
pico_sdk_init()

include(example_auto_set_url.cmake)


if (TARGET tinyusb_device)

    add_executable(gate
                main.cpp
                )
    add_subdirectory(include)
    add_subdirectory(src)

    # Pull in our pico_stdlib which pulls in com
    target_link_libraries(gate pico_stdlib)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(gate 1)
    pico_enable_stdio_uart(gate 0)

    # Create map/bin/hex file etc.
    pico_add_extra_outputs(gate)

    # add url via pico_set_program_url
    example_auto_set_url(gate)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in
    the SDK")

endif()

