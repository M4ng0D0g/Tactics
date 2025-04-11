#include "ComponentFactory.h"
#include "ui/components/options/CommonOps.h"
#include "ui/components/options/ImageOps.h"
#include "ui/managers/TextureManager.h"
#include "ui/components/Image.h"
#include "ui/components/Panel.h"
#include "ui/components/Button.h"

std::shared_ptr<Panel> ComponentFactory::createBackground(const CommonOps& ops) {
	TextureManager& textureManager = TextureManager::getInstance();

	ImageOps imageOps({0, 0}, ops.getSize());
	imageOps.setTexture(textureManager.getTexture("background"));
	std::shared_ptr<Image> image = std::make_shared<Image>(imageOps);

	CommonOps panelOps({0, 0}, ops.getSize());
	std::shared_ptr<Panel> panel = std::make_shared<Panel>(panelOps);
	panel->addComponent(image);

	return panel;
}

std::shared_ptr<GridPanel> ComponentFactory::createBoard(const CommonOps& ops) {
	TextureManager& textureManager = TextureManager::getInstance();
	
	std::shared_ptr<GridPanel> board = std::make_shared<GridPanel>(ops);
	board->setDimension(12, 12);
	
	sf::Vector2f tileSize(90, 90);
	board->setCellSize(tileSize);

	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 12; j++) {
			CommonOps tileOps({0, 0}, tileSize);
			bool isBlack = (i / 4 + j / 4) % 2 == 0;

			std::shared_ptr<Panel> tile = createTile(tileOps, isBlack);
			board->addComponent(tile, i + j * 12);
		}
	}
	board->applyLayout();

	return board;
}

std::shared_ptr<Panel> ComponentFactory::createTile(const CommonOps& ops, bool isBlack) {
	TextureManager& textureManager = TextureManager::getInstance();

	std::shared_ptr<Panel> panel = std::make_shared<Panel>(ops);
	std::weak_ptr<Panel> weakPanel = panel;

	ImageOps imageOps({0, 0}, ops.getSize());
	imageOps.setTexture(textureManager.getTexture(isBlack ? "black_tile" : "white_tile"));
	std::shared_ptr<Image> image = std::make_shared<Image>(imageOps);

	std::shared_ptr<Button> button = std::make_shared<Button>(ops);
	std::weak_ptr<Button> weakButton = button;
	button->setPressCallback(sf::Mouse::Button::Left, [weakButton](button) {
		std::cout << "Button at " << weakButton.lock()->getGlobalPos().x
			<< ", " << weakButton.lock()->getGlobalPos().y
			<< " has been clicked.\n";
	});

	panel->addComponent(image).addComponent(button);
	panel->applyLayout();

	return panel;
}