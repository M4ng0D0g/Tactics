#pragma once

#include "ui/components/options/CommonOps.h"
#include <SFML/Graphics.hpp>
#include <optional>

/**
 * @brief 所有元件的基底
 */
class BaseComponent {
protected:
	sf::Vector2f _globalPos, _relativePos, _size;
	bool _active = true;
	bool _visible = true;

public:
	/**
	 * @brief 建構元件
	 * @param ops 元件的操作參數
	 */
	BaseComponent(const CommonOps& ops) : _relativePos(ops.getPosition()), _size(ops.getSize()) {}
	virtual ~BaseComponent() = default;

	/**
	 * @brief 取得元件全局位置
	 * @return const sf::Vector2f& 全局位置
	 */
	const sf::Vector2f& getGlobalPos() const { return _globalPos; }
	/**
	 * @brief 取得元件相對位置
	 * @return const sf::Vector2f& 相對位置
	 */
	const sf::Vector2f& getRelativePos() const { return _relativePos; }

	/**
	 * @brief 設定元件相對位置
	 * @param pos 新的相對位置
	 */
	virtual void setRelativePos(const sf::Vector2f& pos) { _relativePos = pos; }

	/**
	 * @brief 同步元件的全局位置
	 * @param parentPos 父元件的位置
	 */
	virtual void syncGlobalPos(const sf::Vector2f& parentPos) { 
		_globalPos = {parentPos.x + _relativePos.x, parentPos.y + _relativePos.y}; 
	}

	/**
	 * @brief 取得元件尺寸
	 * @return const sf::Vector2f& 元件尺寸
	 */
	const sf::Vector2f& getSize() const { return _size; }

	/**
	 * @brief 設定元件尺寸
	 * @param size 新的尺寸
	 */
	virtual void setSize(const sf::Vector2f& size) { _size = size; }

	/**
	 * @brief 取得元件可見性
	 * @return bool 是否可見
	 */
	void setActive(bool active) { _active = active; }

	/**
	 * @brief 設定元件可見性
	 * @param v 是否可見
	 */
	bool isActive() const { return _active; }

	/**
	 * @brief 虛擬函式，繪製元件到指定的窗口上
	 * @param window SFML渲染窗口
	 */
	virtual void render(sf::RenderWindow& window) { if(!_visible) return; }

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

	/**
	 * @brief 處理輸入事件
	 * @param event SFML事件，可為空
	 * @return bool 是否處理了事件
	 * @note 如果事件被處理，則返回 true，否則返回 false
	 */
	virtual bool handleEvent(const std::optional<sf::Event>& event) { return false; }
	
};