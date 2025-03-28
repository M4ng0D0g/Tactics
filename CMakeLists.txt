cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

project(Tactics)

# 設定路徑變數
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML-3.0.0)
set(ENET_DIR ${CMAKE_SOURCE_DIR}/lib/enet)
set(NLOHMANN_DIR ${CMAKE_SOURCE_DIR}/lib/nlohmann)
set(FREETYPE_DIR ${CMAKE_SOURCE_DIR}/lib/freetype)

set(TEST_INCLUDE ${CMAKE_SOURCE_DIR}/include/test)
set(SERVER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/server)
set(COMMON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/common)
set(CLIENT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/client)

# 定義 SFML_STATIC 宏，告訴編譯器使用靜態庫
add_definitions(-DSFML_STATIC)

# 設定 SFML 靜態庫列表（MinGW 64-bit 靜態庫）
set(SFML_LIBRARIES 
    ${SFML_DIR}/lib/libsfml-graphics-s.a
    ${SFML_DIR}/lib/libsfml-window-s.a
    ${SFML_DIR}/lib/libsfml-system-s.a
)

# 建立可執行檔並連結 lib
add_executable(Tactics-Test
    src/test/main.cpp
)
target_include_directories(Tactics-Test PRIVATE 
    ${SFML_DIR}/include
    ${ENET_DIR}/include
    ${NLOHMANN_DIR}
    ${FREETYPE_DIR}/include
    ${TEST_INCLUDE_DIR}
)
target_link_libraries(Tactics-Test PRIVATE
    ${SFML_LIBRARIES}
    gdi32
    opengl32
    ${FREETYPE_DIR}/lib/freetype.a
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)

add_executable(Tactics-Server
    src/server/main.cpp
    src/server/connection/Server.cpp
    src/server/connection/PacketHandler.cpp
    src/server/gui/ConsoleWindow.cpp
    # src/server/game/core/Game.cpp
)
target_include_directories(Tactics-Server PRIVATE 
    ${SFML_DIR}/include
    ${ENET_DIR}/include
    ${NLOHMANN_DIR}
    ${FREETYPE_DIR}/include
    ${SERVER_INCLUDE_DIR}
    ${COMMON_INCLUDE_DIR}
)
target_link_libraries(Tactics-Server PRIVATE
    ${SFML_LIBRARIES}
    gdi32
    opengl32
    ${FREETYPE_DIR}/lib/freetype.a
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)

add_executable(Tactics-Client
    src/client/main.cpp
    src/client/connection/Client.cpp
    src/client/connection/PacketHandler.cpp

    src/client/gui/MainWindow.cpp
    src/client/gui/screen/TestScreen.cpp
)
target_include_directories(Tactics-Client PRIVATE
    ${SFML_DIR}/include
    ${ENET_DIR}/include
    ${NLOHMANN_DIR}
    ${FREETYPE_DIR}/include
    ${CLIENT_INCLUDE_DIR}
    ${COMMON_INCLUDE_DIR}
)
target_link_libraries(Tactics-Client PRIVATE
    ${SFML_LIBRARIES}
    gdi32
    opengl32
    ${FREETYPE_DIR}/lib/freetype.a
    ${ENET_DIR}/lib/libenet.a
    ws2_32
    winmm
)