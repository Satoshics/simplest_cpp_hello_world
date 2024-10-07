cmake_minimum_required(VERSION 3.20)

project(simplest_hello_world)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_FLAGS -m32)

add_executable(hello_world
    main.cpp
    classes.cpp
)

# Include directories
target_include_directories(hello_world
  PRIVATE
  ${PROJECT_SOURCE_DIR}/headers
)
