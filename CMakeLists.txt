cmake_minimum_required(VERSION 3.10)
project(Tactics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 設定路徑變數
set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/lib/raylib)
set(ENET_DIR ${CMAKE_SOURCE_DIR}/lib/enet)
set(SERVER_LIB_DIR ${CMAKE_SOURCE_DIR}/include/server)
set(CLIENT_LIB_DIR ${CMAKE_SOURCE_DIR}/include/client)
set(COMMON_LIB_DIR ${CMAKE_SOURCE_DIR}/include/common)

# 包含頭文件
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${RAYLIB_DIR}/include)
include_directories(${ENET_DIR}/include)
include_directories(${CLIENT_LIB_DIR})
include_directories(${SERVER_LIB_DIR})

# 設定共用函式庫
# add_library(GameCore STATIC
#     ${CMAKE_SOURCE_DIR}/include
# )

# 建立可執行檔並連結 lib
add_executable(Tactics-Server src/server/ServerMain.cpp)
target_link_libraries(Tactics-Server PRIVATE
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)

add_executable(Tactics-Client src/client/ClientMain.cpp)
target_link_libraries(Tactics-Client PRIVATE
    ${RAYLIB_DIR}/lib/libraylib.a
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)
