#pragma once

#include "interfaces/UIComponent.h"
#include "interfaces/IClickable.h"
#include "interfaces/IRenderable.h"

/**
 * @brief 按鈕元件類，處理滑鼠點擊和懸停事件
 * 
 */
class Button : public UIComponent, public IClickable, public IRenderable {
private:
	sf::RectangleShape _rect;

public:
	/**
	 * @brief 構造函數
	 * @param pos 按鈕位置
	 * @param size 按鈕尺寸
	 */
	Button(const sf::Vector2f& pos, const sf::Vector2f& size) : UIComponent(pos, size) {
		setRectangle();
	}

	void setRectangle(const sf::RectangleShape& rect = sf::RectangleShape()) {
		_rect = rect;
		_rect.setSize(_size);
		_rect.setPosition(_globalPos);
		_rect.setFillColor(sf::Color::White);
		_rect.setOutlineThickness(1.f);
		_rect.setOutlineColor(sf::Color::Black);
	}

	bool handleEvent(const std::optional<sf::Event>& event) override {
		if(!event) return false;
		if(auto* mb = event->getIf<sf::Event::MouseButtonPressed>() && onPress(*mb)) return true;
		if(auto* mb = event->is<sf::Event::MouseButtonReleased>() && onRelease(*mb)) return true;
		return false;
	}

	/**
	 * @brief 處理滑鼠按下事件
	 * @param mb 滑鼠按鈕事件資訊
	 * @return 如果有對應的回調函數被執行則返回true，否則返回false
	 */
	[[nodiscard]]
	bool onPress(const sf::Event::MouseButtonPressed& mb) override {
		if(!(containPos(mb.position) && _active)) return false;
		_isPressed[mb.button] = true;
		const auto& cb = _callbacks[mb.button].press;
		if(cb) { cb(*this); return true; }
		return false;
	}

	/**
	 * @brief 處理滑鼠釋放事件
	 * @param mb 滑鼠按鈕事件資訊
	 * @return 如果有對應的回調函數被執行則返回true，否則返回false
	 */
	[[nodiscard]]
	bool onRelease(const sf::Event::MouseButtonReleased& mb) override {
		if(!(containPos(mb.position) && _active)) return false;
		_isPressed[mb.button] = false;
		const auto& cb = _callbacks[mb.button].release;
		if(cb) { cb(*this); return true; }
		return false;
	}

	void syncPosition(const sf::Vector2f& parentPos) override {
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y};
		_rect.setPosition(_globalPos);
	}

	void setSize(const sf::Vector2f& size) override {
		_size = size;
		_rect.setSize(size);
	}

	void render(sf::RenderWindow& window) override {
		if(!_visible) return;
		window.draw(_rect);
	}
};
