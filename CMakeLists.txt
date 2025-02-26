cmake_minimum_required(VERSION 3.10)
project(Tactics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 設定lib目錄
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/lib/raylib)

# 包含lib頭文件和庫
include_directories(${RAYLIB_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

# 建立可執行檔
add_executable(Tactics src/main.cpp)

# 自動尋找lib並連結
find_library(RAYLIB_LIB NAMES raylib PATHS ${RAYLIB_DIR}/lib)
target_link_libraries(Tactics PRIVATE ${RAYLIB_LIB})

# MinGW 需要額外連結 winmm
if (MINGW)
    target_link_libraries(Tactics PRIVATE winmm)
endif()
