#pragma once

#include "components/Button.h"
#include <unordered_map>
#include <string>
#include <functional
#include <memory>

class UIFactory {
public:
	UIFactory() = default;

	static std::shared_ptr<Button> createButton() {

	}

	static std::shared_ptr<Label> createLabel() {

	}
	
};

#endif