cmake_minimum_required(VERSION 3.10)
project(Tactics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/lib/raylib/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/raylib/lib)

add_executable(Tactics src/main.cpp)
target_link_libraries(Tactics raylib)