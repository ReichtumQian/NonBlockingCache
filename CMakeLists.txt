cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
project("NonBlocking Cache")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-std=c++2a ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)


include_directories(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main SRC)

