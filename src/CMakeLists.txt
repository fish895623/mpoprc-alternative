file(GLOB SRCS *.cpp *.hpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${CONAN_LIBS})
