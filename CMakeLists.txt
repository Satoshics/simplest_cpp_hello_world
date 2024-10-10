cmake_minimum_required(VERSION 3.20)

project(simplest_hello_world)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        message(FATAL_ERROR "This project requires a 32-bit build")
    endif()
endif()
	
add_executable(hello_world
	main.cpp
	classes.cpp
	functions/functions.cpp
)

target_include_directories(hello_world
  PRIVATE
  ${PROJECT_SOURCE_DIR}/functions
)

target_include_directories(hello_world
  PRIVATE
  ${PROJECT_SOURCE_DIR}/headers
)
