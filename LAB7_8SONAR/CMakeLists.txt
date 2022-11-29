cmake_minimum_required(VERSION 3.23)
project(LAB7 C)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping -O0 -g")
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -fprofile-instr-generate -fcoverage-mapping -O0 -g")
set(CMAKE_C_STANDARD 99)

add_executable(LAB7 main.c IO.h IO.c Array.h Array.c SO.c SO.h Sort.c Sort.h)
