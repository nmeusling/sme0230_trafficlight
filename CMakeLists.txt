cmake_minimum_required(VERSION 3.6)
project(sme0230_trafficlight)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        src/board.c
        src/main.c)

add_executable(sme0230_trafficlight ${SOURCE_FILES})