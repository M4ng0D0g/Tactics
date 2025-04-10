#pragma once

#include <SFML/Graphics.hpp>

class IRenderable {
protected:
	bool _visible = true;

public:
	virtual ~IRenderable() = default;

	/**
	 * @brief 虛擬函式，繪製元件到指定的窗口上
	 * @param window SFML渲染窗口
	 */
	virtual void render(sf::RenderWindow& window) = 0;

	/**
	 * @brief 取得元件可見性
	 * @return bool 是否可見
	 */
	bool isVisible() const noexcept { return _visible; }

	/**
	 * @brief 設定元件可見性
	 * @param v 是否可見
	 */
	void setVisible(bool v) noexcept { _visible = v; }
};