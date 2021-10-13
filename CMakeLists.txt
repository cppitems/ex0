cmake_minimum_required(VERSION 3.0)

# adds some custom default flags for all CXX targets
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -pedantic") 
message(STATUS "CMAKE_CXX_FLAGS=" ${CMAKE_CXX_FLAGS})

project(ex0 LANGUAGES CXX)

# configuring address sanitizer flags (ASAN); 
# usage: $ cmake -D CMAKE_BUILD_TYPE=ASAN ..
set(CMAKE_CXX_FLAGS_ASAN "-fno-omit-frame-pointer -fsanitize=address -g")
set(CMAKE_EXE_LINKER_ASAN "-fno-omit-frame-pointer -fsanitize=address")

# OPTION 1
# header-only library target, i.e., vector.cpp is not relevant 
# -> a user only needs to include the headers 
# add_library(vector INTERFACE)
# target_include_directories(vector INTERFACE "include") 

# OPTION 2
# now using a "real library", i.e., interface and implementation are separated 
# -> a user has to include the header, and link to the compiled library file
add_library(vector SHARED lib/vector.cpp)
target_include_directories(vector PUBLIC "include")

# enable tests with ctest (which is included in cmake)
# usage: $ ctest --verbose
enable_testing()

# check this folder for a CMakeLists.txt to process
add_subdirectory("tests")