#pragma once

#include "interface/UILayout.h"

class FreeLayout : public UILayout {
public:
	void applyLayout(std::vector<std::shared_ptr<UIComponent>>& components) override {}

};