cmake_minimum_required(VERSION 2.8)
project(AI4GAMES)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ai4games)



add_subdirectory(src)
add_subdirectory(examples)