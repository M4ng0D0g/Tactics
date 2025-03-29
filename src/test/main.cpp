#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <memory>
#include <optional>
#include <iostream>
#include <vector>

// void setupOpenGL() {
//     glEnable(GL_DEPTH_TEST); // 啟用深度測試，讓遠處物體被遮擋
//     glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 設置背景顏色為黑色
//     glMatrixMode(GL_PROJECTION); // 設置投影矩陣模式
//     glLoadIdentity(); // 清除現有矩陣
//     gluPerspective(45.0f, 1.33f, 0.1f, 100.0f); // 設置視角和遠近剪裁面
//     glTranslatef(0.0f, 0.0f, -5.0f); // 使 3D 物體在屏幕上可見
// }

// void drawCube() {
//     glBegin(GL_QUADS); // 開始繪製方塊的四邊形面
//     // 前面
//     glColor3f(1.0f, 0.0f, 0.0f); // 紅色
//     glVertex3f(-1.0f, -1.0f, 1.0f);
//     glVertex3f( 1.0f, -1.0f, 1.0f);
//     glVertex3f( 1.0f,  1.0f, 1.0f);
//     glVertex3f(-1.0f,  1.0f, 1.0f);

//     // 背面
//     glColor3f(0.0f, 1.0f, 0.0f); // 綠色
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f(-1.0f,  1.0f, -1.0f);
//     glVertex3f( 1.0f,  1.0f, -1.0f);
//     glVertex3f( 1.0f, -1.0f, -1.0f);

//     // 左面
//     glColor3f(0.0f, 0.0f, 1.0f); // 藍色
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f(-1.0f, -1.0f,  1.0f);
//     glVertex3f(-1.0f,  1.0f,  1.0f);
//     glVertex3f(-1.0f,  1.0f, -1.0f);

//     // 右面
//     glColor3f(1.0f, 1.0f, 0.0f); // 黃色
//     glVertex3f(1.0f, -1.0f, -1.0f);
//     glVertex3f(1.0f,  1.0f, -1.0f);
//     glVertex3f(1.0f,  1.0f,  1.0f);
//     glVertex3f(1.0f, -1.0f,  1.0f);

//     // 上面
//     glColor3f(1.0f, 0.0f, 1.0f); // 紫色
//     glVertex3f(-1.0f, 1.0f, -1.0f);
//     glVertex3f(-1.0f, 1.0f,  1.0f);
//     glVertex3f( 1.0f, 1.0f,  1.0f);
//     glVertex3f( 1.0f, 1.0f, -1.0f);

//     // 下面
//     glColor3f(0.0f, 1.0f, 1.0f); // 青色
//     glVertex3f(-1.0f, -1.0f, -1.0f);
//     glVertex3f( 1.0f, -1.0f, -1.0f);
//     glVertex3f( 1.0f, -1.0f,  1.0f);
//     glVertex3f(-1.0f, -1.0f,  1.0f);
//     glEnd(); // 結束繪製
// }

class Circle {
private:
    sf::CircleShape _circle;
public:
    Circle(float raduis, sf::Color color, float outline, sf::Vector2f position) {
        _circle.setRadius(raduis);
        _circle.setOutlineColor(color);
        _circle.setOutlineThickness(outline);
        _circle.setPosition(position);
    }

    const sf::CircleShape& getObj() {
        return _circle;
    }
};

class Cell {
private:
    sf::RectangleShape _rectangle;
public:
    Cell() = default;
    Cell(sf::Vector2f size, sf::Color color, sf::Color outlineColor, sf::Vector2f position) {
        _rectangle.setSize(size);
        _rectangle.setFillColor(color);
        _rectangle.setOutlineColor(outlineColor);
        _rectangle.setOutlineThickness(5.6);
        _rectangle.setPosition(position);
    }

    const sf::RectangleShape& getObj() {
        return _rectangle;
    }
};


int main() {
	std::cout << "Hello, World!" << std::endl;

	sf::RenderWindow window(sf::VideoMode({1920, 1008}), "Test Screen");
	window.setFramerateLimit(60);

	// setupOpenGL(); // 設置 OpenGL

    // Circle c0(150, sf::Color::Red, 5, {10, 20});
    // Circle c1(100, sf::Color::Blue, 15, {50, 100});
    // Circle c2(200, sf::Color::Green, 10, {200, 50});

    int boardR = 16;
    std::vector<std::vector<Cell>> board(boardR, std::vector<Cell>(boardR, Cell()));

    for(int i=0; i<boardR; i++) {
        for(int j=0; j<boardR; j++) {

            sf::Vector2f size(45, 45);
            float offset = 1.3;

            sf::Color fc, olc;
            if((j / 4 & 1) == (i / 4 & 1)) {
                fc = sf::Color(80, 80, 80, 255);
                olc = sf::Color(60, 60, 60, 255);
            }
            else {
                fc = sf::Color(220, 220, 220, 255);
                olc = sf::Color(200, 200, 200, 255);
            }
             
            sf::Vector2f pos = {size.x * i * offset + 8, size.y * j * offset + 14};
            board[i][j] = Cell(size, fc, olc, pos);
        }
    }

	while(window.isOpen()) {
		while(const std::optional event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) window.close();
		}

		// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清除屏幕和深度緩衝區
        // drawCube(); // 繪製 3D 方塊

        window.clear(sf::Color(0, 0, 0));

        for(int i=0; i<boardR; i++) {
            for(int j=0; j<boardR; j++) {
                window.draw(board[i][j].getObj());
            }
        }

		window.display();
	}

	return 0;
}
