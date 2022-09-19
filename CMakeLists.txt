cmake_minimum_required(VERSION 3.5)
project(validator)

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake")
    execute_process(COMMAND conan install .. --build=missing
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
else()
    execute_process(COMMAND conan install .. --build=missing
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
endif()

conan_basic_setup(TARGETS)

add_subdirectory(src)