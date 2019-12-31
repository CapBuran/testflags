cmake_minimum_required(VERSION 3.11)

project(TestFlags)

add_executable(${PROJECT_NAME})

target_sources_local(${PROJECT_NAME} PRIVATE unitFlug.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE gtest_main)
