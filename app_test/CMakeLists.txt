cmake_minimum_required(VERSION 3.27)
project(Bubble)

set(CMAKE_C_STANDARD 99)

add_executable(test example.c exampleFunc.c)

link_directories(${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test libolytics)

