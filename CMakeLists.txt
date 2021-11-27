cmake_minimum_required(VERSION 3.1)

project(ReadWriteStruct)
add_library(ReadWriteStruct SHARED src/ReadWriteStruct.c)
add_executable(ReadWriteStruct.test tests/ReadWriteStruct.Test.cpp)
target_link_libraries(ReadWriteStruct.test ReadWriteStruct gtest gtest_main pthread)