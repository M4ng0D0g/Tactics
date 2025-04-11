#pragma once

#include "options/CommonOps.h"
#include "interfaces/BaseComponent.h"
#include "interfaces/IClickable.h"
#include "interfaces/IHittable.h"

/**
 * @brief 按鈕元件類，處理滑鼠點擊和懸停事件
 * 
 */
class Button : public BaseComponent, public IClickable, public IHittable {
private:
	sf::RectangleShape _rect;

public:
	/**
	 * @brief 構造函數
	 * @param ops 按鈕操作參數
	 */
	Button(const CommonOps& ops) : BaseComponent(ops) {
		_rect.setSize(_size);
		_rect.setFillColor(sf::Color::White);
		_rect.setOutlineThickness(1.f);
		_rect.setOutlineColor(sf::Color::Black);
	}

	bool handleEvent(const std::optional<sf::Event>& event) override {
		if(!event || !isMouseOver(_globalPos, _size)) return false;
		if(auto* mb = event->getIf<sf::Event::MouseButtonPressed>()) {
			if(onPress(*mb)) return true;
		}
		if(auto* mb = event->getIf<sf::Event::MouseButtonReleased>()) {
			if(onRelease(*mb)) return true;
		}
		return false;
	}

	/**
	 * @brief 處理滑鼠按下事件
	 * @param mb 滑鼠按鈕事件資訊
	 * @return 如果有對應的回調函數被執行則返回true，否則返回false
	 */
	[[nodiscard]]
	bool onPress(const sf::Event::MouseButtonPressed& mb) override {
		if(!isMouseOver(_globalPos, _size) || !_active) return false;
		_isPressed[static_cast<size_t>(mb.button)] = true;

		const auto& cb = _callbacks[static_cast<size_t>(mb.button)].press;
		if(cb) {
			cb(*this);
			return true;
		}
		return false;
	}

	/**
	 * @brief 處理滑鼠釋放事件
	 * @param mb 滑鼠按鈕事件資訊
	 * @return 如果有對應的回調函數被執行則返回true，否則返回false
	 */
	[[nodiscard]]
	bool onRelease(const sf::Event::MouseButtonReleased& mb) override {
		if(!_active) return false;

		if(_isPressed[static_cast<size_t>(mb.button)]) {
			if(!isMouseOver(_globalPos, _size)) {
				const auto& cb = _callbacks[static_cast<size_t>(mb.button)].release;
				if(cb) cb(*this);
			}
			_isPressed[static_cast<size_t>(mb.button)] = false;
		}		
		return false;
	}

	void syncGlobalPos(const sf::Vector2f& parentPos) override {
		BaseComponent::syncGlobalPos(parentPos);
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
