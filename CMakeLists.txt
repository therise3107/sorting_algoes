cmake_minimum_required(VERSION 3.16)
project(sorting)

set(CMAKE_CXX_STANDARD 14)

# Include the headers
include_directories(include)

# Add sources
file(GLOB SOURCES "src/*.cpp")

add_executable(sorting ${SOURCES})