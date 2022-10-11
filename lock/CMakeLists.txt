cmake_minimum_required(VERSION 3.22)

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

    add_executable(${PROJECT_NAME}
                main.cpp
                )
    # add_subdirectory(include)
    # add_subdirectory(src)

    target_include_directories(${PROJECT_NAME} PUBLIC uart)
    target_link_directories(${PROJECT_NAME} PRIVATE uart)
    target_link_libraries(${PROJECT_NAME} uart)


    # Pull in our pico_stdlib which pulls in com
    target_link_libraries(${PROJECT_NAME} pico_stdlib)

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

