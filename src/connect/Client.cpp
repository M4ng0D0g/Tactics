#include "raylib.h"
#include <iostream>
#include <thread>
#include <arpa/inet.h>
#include <unistd.h>  // close()
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024

struct Player {
    sockaddr_in addr;
    float x, y;
};

Player players[10];
int playerCount = 0;
int clientSocket;
sockaddr_in serverAddr;
float myX = 400, myY = 300;

void ReceiveUpdates() {
    while (true) {
        char buffer[BUFFER_SIZE];
        ssize_t bytesReceived = recvfrom(clientSocket, buffer, BUFFER_SIZE, 0, nullptr, nullptr);
        if (bytesReceived <= 0) continue;

        playerCount = bytesReceived / sizeof(Player);
        memcpy(players, buffer, bytesReceived);
    }
}

int main() {
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    std::thread(ReceiveUpdates).detach();  // 開啟接收執行緒

    InitWindow(800, 600, "Multiplayer Game (UDP)");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // 控制角色移動
        if (IsKeyDown(KEY_W)) myY -= 3.0f;
        if (IsKeyDown(KEY_S)) myY += 3.0f;
        if (IsKeyDown(KEY_A)) myX -= 3.0f;
        if (IsKeyDown(KEY_D)) myX += 3.0f;

        // 發送位置到伺服器
        float pos[2] = {myX, myY};
        sendto(clientSocket, pos, sizeof(pos), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

        // 畫面更新
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 畫出自己
        DrawCircle(myX, myY, 10, BLUE);

        // 畫出其他玩家
        for (int i = 0; i < playerCount; i++) {
            DrawCircle(players[i].x, players[i].y, 10, RED);
        }

        DrawText("WASD to move", 10, 10, 20, BLACK);
        EndDrawing();
    }

    close(clientSocket);
    CloseWindow();
    return 0;
}
