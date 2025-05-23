# Set Project Configs
cmake_minimum_required(VERSION 3.22)
project(DA_PROJ2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Disable experimental C++20 modules
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "OFF")

# Define source and header directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src/algorithms")
set(HEADERS_DIR "${CMAKE_SOURCE_DIR}/src/headers")
set(STRUCTS_DIR "${CMAKE_SOURCE_DIR}/src/other")

# Gather source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${HEADERS_DIR}/*.h" "${STRUCTS_DIR}/*.h")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
include_directories(${HEADERS_DIR} ${STRUCTS_DIR})
