#include "ui/widgets/TileUI.h"

TileUI::TileUI() {
	_panel->addComponent(_image);
	_panel->addComponent(_button);
	_panel->setLayout(std::make_shared<FreeLayout>());
	_panel->applyLayout();
}