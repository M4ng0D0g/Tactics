#include "test/ui/screens/TestScreen.h"
#include "common/ui/managers/TextureManager.h"

#include "ui/components/Button.h"
#include "ui/components/Image.h"
#include "ui/components/Panel.h"
// #include "ui/layouts/FreeLayout.h"
// #include "ui/layouts/GridLayout.h"

#include <vector>
#include <iostream>

TestScreen::TestScreen(const sf::Vector2i& windowSize) {
	TextureManager textureManager = TextureManager::getInstance();
	textureManager.loadTexture("background", "texture/background.png");
	textureManager.loadTexture("white_tile", "texture/white_tile.png");
	textureManager.loadTexture("black_tile", "texture/black_tile.png");

	std::shared_ptr<Image> backgroundImage = std::make_shared<Image>({0, 0}, windowSize);
	backgroundImage->setTexture(textureManager.getTexture("background"));

	// auto tileLayout = std::make_shared<FreeLayout>();
	// auto boardLayout = std::make_shared<GridLayout>(12, 12);

	std::shared_ptr<Panel> boardPanel = std::make_shared<Panel>({460, 50}, {0, 0});

	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 12; j++) {
			std::shared_ptr<Panel> tilePanel = std::make_shared<Panel>({0, 0}, {90, 90});
			std::shared_ptr<Button> tileButton = std::make_shared<Button>({0, 0}, {90, 90});
			std::shared_ptr<Image> tileImage = std::make_shared<Image>({0, 0}, {90, 90});

			tileButton->setPressCallback(sf::Mouse::Button::Left, [tilePanel]() {
				std::cout
					<< "Button at" << tilePanel->
					<< "," << tilePanel->_position.y
					<< "has been clicked.\n"
			});

			bool isBlack = ((i / 4 + j / 4) % 2) == 0;
			tileImage->setTexture(textureManager.getTexture(isBlack ? "black_tile" : "white_tile"));

			tilePanel->addComponent(tileButton);
			tilePanel->addComponent(tileImage);
			boardPanel->addComponent(tilePanel);
		}
	}

	boardPanel->applyLayout();

	_screen.addComponent(backgroundImage, 0);
	_screen.addComponent(boardPanel, 10);
}