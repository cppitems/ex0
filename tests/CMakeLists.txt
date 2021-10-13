cmake_minimum_required(VERSION 3.0)

# variables from parent scope like "CMAKE_CXX_FLAGS" are valid here, too

project(Tests LANGUAGES CXX)

# add "regular" executable
add_executable(TestA_Constructor TestA_Constructor.cpp)
# link to our vector library "privately" (which might be header-only or a "regular library")
target_link_libraries(TestA_Constructor PRIVATE vector)
# mark the executable target as a test and specify the command to call it
add_test(NAME TestA_Constructor COMMAND TestA_Constructor)

## TODO: add other tests 