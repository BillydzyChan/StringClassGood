include(CMakeToolsHelpers OPTIONAL)
cmake_minimum_required(VERSION 2.8)

project(sayings)

aux_source_directory(. DIR_SRCS)
add_executable(sayings ${DIR_SRCS}) 