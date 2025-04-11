#pragma once

#include "options/CommonOps.h"
#include "interfaces/IPanel.h"
#include <algorithm>
#include <vector>
#include <memory>

/**
 * @brief 可容納子元件並套用版面配置的 Panel。
 */
class Panel : public IPanel {
public:
	Panel(const CommonOps& ops) : IPanel(ops) {}
	
	void applyLayout() override {} //Do nothing.

	/**
	 * @brief 更新面板的大小以適應所有子元件。
	 * @details 此函數會遍歷所有子元件，計算它們的最大寬度和高度，並更新面板的大小。
	 */
	//TODO:改成裁切
	// void updateSize() {
	// 	sf::Vector2f size = {0.f, 0.f};
	// 	for (const auto& comp : _components) {
	// 		size.x = std::max(size.x, comp->getPosition().x + comp->getSize().x);
	// 		size.y = std::max(size.y, comp->getPosition().y + comp->getSize().y);
	// 	}
	// 	_size = size;
	// }

	
};