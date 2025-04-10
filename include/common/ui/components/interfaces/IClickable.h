#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <array>

class IClickable {
public:
	/** @brief Callback function type definition
	 *  @brief 回調函數類型定義 */
	using Callback = std::function<void(const IClickable&)>;

protected:
	/** @brief Press and release callback function pair
	 *  @brief 按下與釋放回調函數對 */
	struct CallbackPair { Callback press {}; Callback release {}; };

	std::array<CallbackPair, sf::Mouse::ButtonCount> _callbacks {};
	std::array<bool, sf::Mouse::ButtonCount> _isPressed {};

public:
	virtual ~IClickable() = default;

	/** @brief 處理滑鼠按下事件
	 *  @param mb 滑鼠按鈕事件資訊
	 *  @return 如果有對應的回調函數被執行則返回true，否則返回false */
	[[nodiscard]]
	virtual bool onPress(const sf::Event::MouseButtonPressed& mb) = 0;

	/** @brief 處理滑鼠按下事件
	 *  @param mb 滑鼠按鈕事件資訊
	 *  @return 如果有對應的回調函數被執行則返回true，否則返回false */
	[[nodiscard]]
	virtual bool onRelease(const sf::Event::MouseButtonReleased& mb) = 0;
	
	/**
	 * @brief 設置按鈕按下時的回調函數
	 * @param b 滑鼠按鈕類型
	 * @param cb 回調函數
	 */
	void setPressCallback(sf::Mouse::Button b, Callback cb) {
		_callbacks[static_cast<size_t>(b)].press = std::move(cb);
	}

	/**
	 * @brief 設置按鈕釋放時的回調函數
	 * @param b 滑鼠按鈕類型
	 * @param cb 回調函數
	 */
	void setReleaseCallback(sf::Mouse::Button b, Callback cb) {
		_callbacks[static_cast<size_t>(b)].release = std::move(cb);
	}

	/**
	 * @brief 清除所有回調函數
	 */
	void clearCallbacks() { _callbacks.fill({}); }

	/**
	 * @brief 檢查指定的滑鼠按鈕是否處於按下狀態
	 * @param b 要檢查的滑鼠按鈕
	 * @return 如果按鈕被按下則返回true，否則返回false
	 */
	bool isPressed(sf::Mouse::Button b) const noexcept {
		return _isPressed[static_cast<size_t>(b)];
	}

};