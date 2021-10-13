cmake_minimum_required(VERSION 3.0.0)
project(cmakeTest VERSION 0.1.0)

add_executable( noneUseLib main.cpp)

add_library(hello_share SHARED libhello.cpp)
add_executable(uselibhello useLibhello.cpp)
target_link_libraries(uselibhello hello_share)

