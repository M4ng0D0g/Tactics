#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <unistd.h>  // close()
#include <arpa/inet.h>

using namespace std;

#define PORT
#define BUFFER_SIZE 1024

struct Player {
    sockaddr_in addr;
    float x, y;
};

vector<Player> players;
vector<mutex> playersMutex;

void ServerLoop(int serverSocket) {
    sockaddr_in clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    while (true) {
        ssize_t bytesReceived = recvfrom(serverSocket, buffer, BUFFER_SIZE, 0,
                                         (struct sockaddr*)&clientAddr, &addrLen);
        if (bytesReceived <= 0) continue;

        float pos[2];
        memcpy(pos, buffer, sizeof(pos));

        playersMutex.lock();
        bool found = false;
        for (auto& player : players) {
            if (memcmp(&player.addr, &clientAddr, sizeof(clientAddr)) == 0) {
                player.x = pos[0];
                player.y = pos[1];
                found = true;
                break;
            }
        }
        if (!found) {
            players.push_back({clientAddr, pos[0], pos[1]});
        }
        playersMutex.unlock();

        // 廣播所有玩家位置
        playersMutex.lock();
        for (const auto& player : players) {
            sendto(serverSocket, players.data(), players.size() * sizeof(Player), 0,
                   (struct sockaddr*)&player.addr, sizeof(player.addr));
        }
        playersMutex.unlock();
    }
}

int main() {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    std::cout << "UDP Server running on port " << PORT << std::endl;

    std::thread(ServerLoop, serverSocket).detach();

    while (true) {
        sleep(10); // 保持伺服器運行
    }

    close(serverSocket);
    return 0;
}




