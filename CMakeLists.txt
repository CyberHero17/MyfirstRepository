cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
project(SpaceCat)

add_compile_options(-Wall -Wall)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(some_test some_test.cpp)

find_package (SFML 2.6.1 COMPONENTS graphics audio network REQUIRED)

target_link_libraries (${PROJECT_NAME} PUBLIC sfml-system sfml-graphics sfml-audio sfml-network)



