#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <memory>
#include <optional>
#include <iostream>
#include <vector>

class Tile {
private:
    sf::Sprite _tile;
public:
    Tile() = default;
    Tile(const sf::Texture& texture, sf::Vector2f size, sf::Vector2f position)
    : _tile(texture) {
        float scaleX = (size.x) / static_cast<float>(texture.getSize().x);
        float scaleY = (size.y) / static_cast<float>(texture.getSize().y);
        _tile.setScale({scaleX, scaleY});
        _tile.setPosition(position);
    }

    const sf::Sprite& getObj() const {
        return _tile;
    }
};


int main() {
	std::cout << "Hello, World!" << std::endl;

	sf::RenderWindow window(sf::VideoMode({1920, 1008}), "Test Screen");
	window.setFramerateLimit(60);

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../assets/texture/background.png")) return -1;

    sf::Sprite background(backgroundTexture);
    float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
    float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
    background.setScale({scaleX, scaleY});

    int boardR = 12;
    std::vector<std::vector<Tile>> board;
    board.resize(boardR);

    sf::Texture whiteTile;
    sf::Texture blackTile;
    if (!whiteTile.loadFromFile("../assets/texture/white_tile.png")) return -1;
    if (!blackTile.loadFromFile("../assets/texture/black_tile.png")) return -1;

    sf::Vector2f size(90, 90);
    sf::Vector2f offset = {0.875, 0.812};

    for(int i = 0; i < boardR; i++) {
        board[i].reserve(boardR);
        for(int j = 0; j < boardR; j++) {
            sf::Texture& texture = (j / 4 & 1) == (i / 4 & 1) ? blackTile : whiteTile;
            // sf::Texture& texture = whiteTile;
            
            sf::Vector2f pos = {size.x * i * offset.x + 460, size.y * j * offset.y + 50};
            board[i].emplace_back(texture, size, pos);
        }
    }

	while(window.isOpen()) {
		while(const std::optional event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) window.close();
		}

        window.draw(background);

        for(int i=0; i<boardR; i++) {
            for(int j=0; j<boardR; j++) {
                window.draw(board[i][j].getObj());
            }
        }

		window.display();
	}

	return 0;
}
