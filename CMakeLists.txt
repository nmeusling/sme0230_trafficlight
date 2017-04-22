cmake_minimum_required(VERSION 3.5)
project(sme0230_trafficlight)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/board.c
        src/main.c
        src/input.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(sme0230_trafficlight ${SOURCE_FILES})