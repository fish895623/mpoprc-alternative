cmake_minimum_required(VERSION 3.5)
project(validator)

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake")
    execute_process(COMMAND conan install ..
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_subdirectory(src)