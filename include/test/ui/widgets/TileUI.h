#pragma once

#include "common/ui/components/Panel.h"
#include "common/ui/components/Image.h"
#include "common/ui/components/Button.h"

class TileUI {
private:
	std::shared_ptr<Image> _image = std::make_shared<Image>({0, 0}, {90, 90});
	std::shared_ptr<Panel> _panel = std::make_shared<Panel>({0, 0}, {90, 90});
	std::shared_ptr<Button> _button = std::make_shared<Button>({0, 0}, {90, 90});
	
public:
	TileUI();
};