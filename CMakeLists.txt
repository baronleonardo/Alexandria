cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(Alexandria C)
set(LIB_TYPE STATIC)

add_subdirectory(inc)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(example)