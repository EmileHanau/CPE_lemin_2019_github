cmake_minimum_required(VERSION 3.15)
project(CPE_lemin_2019 C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRC_DIR
        "src/*.c"
        "src/printf/*c"
        "src/extra/*c")

add_executable(CPE_lemin_2019 ${SRC_DIR})