#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief 定義了可以檢測滑鼠懸浮狀態的UI元件的基本行為
 */
class IHittable {
protected:


public:
	virtual ~IHittable() = default;

	/**
	 * @brief 檢查滑鼠是否懸浮在元件上
	 * @return 如果滑鼠懸浮在元件上則返回true，否則返回false
	 */
	[[nodiscard]]
	virtual bool isMouseOver() const = 0;
};