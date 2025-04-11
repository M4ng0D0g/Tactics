#include "TestScreen.h"
#include "../ComponentFactory.h"
#include "ui/managers/TextureManager.h"
#include "ui/components/options/CommonOps.h"
#include "ui/components/interfaces/Panel.h"
#include <vector>
#include <iostream>

TestScreen::TestScreen(const sf::Vector2i& windowSize) {
	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.loadTexture("background", "../assets/texture/background.png");
    textureManager.loadTexture("white_tile", "../assets/texture/white_tile.png");
    textureManager.loadTexture("black_tile", "../assets/texture/black_tile.png");

	CommonOps bgOps({0, 0}, windowSize);
	std::shared_ptr<Panel> background = ComponentFactory::createBackground(bgOps);

	CommonOps boardOps({460, 50}, {1080, 1080});
	std::shared_ptr<GridPanel> board = ComponentFactory::createBoard(boardOps);

	_screen.addComponent(background, 0);
	_screen.addComponent(board, 10);
}