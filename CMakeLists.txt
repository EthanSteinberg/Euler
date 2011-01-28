cmake_minimum_required(VERSION 2.6)

project(GtkApp)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -march=native -std=c++0x  -g -O0 -Wshadow")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arch)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(Boost_ADDITIONAL_VERSIONS "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
set(BOOST_COMPONENTS system thread date_time filesystem)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} QUIET)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(19) 
add_subdirectory(20) 
add_subdirectory(21) 
add_subdirectory(22) 
add_subdirectory(23) 
add_subdirectory(24) 
add_subdirectory(25) 
add_subdirectory(26) 
add_subdirectory(27) 
add_subdirectory(28) 
add_subdirectory(29) 
add_subdirectory(30) 
add_subdirectory(31) 
add_subdirectory(97) 
add_subdirectory(32) 
add_subdirectory(33) 
