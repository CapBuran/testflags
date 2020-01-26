cmake_minimum_required(VERSION 3.0)

message(STATUS "CMAKE_VERSION='${CMAKE_VERSION}'")
message(STATUS "CMAKE_GENERATOR='${CMAKE_GENERATOR}'")

#option(gtest_force_shared_crt "gtest_force_shared_crt" ON)
#SET(gtest_force_shared_crt ON FORCE)
#SET(gtest_force_shared_crt TRUE CACHE)

set(gtest_force_shared_crt true CACHE BOOL "gtest_force_shared_crt")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS ON)

if(WIN32)
  ## all configurations are using the dynamically loaded release CRT (like 3rd libraries) and multi-processor compilation
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MD /MP")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD /MP -std=c++1z -std=gnu++1z")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /MP -std=c++1z -std=gnu++1z")
  add_definitions(-DWIN32 -D_WIN32 -DWINDOWS -D_WINDOWS -D_WIN32_WINNT=0x0601 -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++17 -lpthread -lrt -ldl -Wno-deprecated-declarations")
endif()

project(TestFlags C CXX)

include(src/CMake/CMakeFunctions.cmake)
include(src/CMake/CMakeDownload.cmake)
include(src/CMake/DownloadProject.cmake)

download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_subdirectory(src/UnitTest)
