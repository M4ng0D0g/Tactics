cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

project(Tactics)

# 設定路徑變數
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML-3.0.0)
set(ENET_DIR ${CMAKE_SOURCE_DIR}/lib/enet)
set(SERVER_LIB_DIR ${CMAKE_SOURCE_DIR}/include/server)
set(CLIENT_LIB_DIR ${CMAKE_SOURCE_DIR}/include/client)
set(COMMON_LIB_DIR ${CMAKE_SOURCE_DIR}/include/common)

# 包含頭文件
include_directories(${SFML_DIR}/include)
include_directories(${ENET_DIR}/include)
#include_directories(${CMAKE_SOURCE_DIR}/include)

# 定義 SFML_STATIC 宏，告訴編譯器使用靜態庫
add_definitions(-DSFML_STATIC)

# 設定 SFML 靜態庫列表（MinGW 64-bit 靜態庫）
set(SFML_LIBRARIES 
    ${SFML_DIR}/lib/libsfml-graphics-s.a
    ${SFML_DIR}/lib/libsfml-window-s.a
    ${SFML_DIR}/lib/libsfml-system-s.a
)

# 建立可執行檔並連結 lib
add_executable(Tactics-Server
    src/server/main.cpp
    src/server/Server.cpp
    src/server/event/PacketHandler.cpp
)
target_include_directories(Tactics-Server PRIVATE 
    ${SERVER_LIB_DIR}
    ${COMMON_LIB_DIR}
)
target_link_libraries(Tactics-Server PRIVATE
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)

add_executable(Tactics-Client
    src/client/main.cpp
    src/client/Client.cpp
    src/client/event/PacketHandler.cpp
)
target_include_directories(Tactics-Client PRIVATE 
    ${CLIENT_LIB_DIR}
    ${COMMON_LIB_DIR}
)
target_link_libraries(Tactics-Client PRIVATE
    ${SFML_LIBRARIES}
    gdi32
    opengl32
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
    
)
