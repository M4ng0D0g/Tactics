#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

/**
 * @brief 所有元件的基底
 */
class UIComponent {
protected:
	sf::Vector2f _globalPos, _relativePos, _size;
	bool _active = true;

public:
	/**
	 * @brief 建構元件
	 * @param pos 相對父級位置
	 * @param size 元件尺寸
	 */
	UIComponent(const sf::Vector2f& pos, const sf::Vector2f& size) : _relativePos(pos), _size(size) {}
	virtual ~UIComponent() = default;

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
	virtual void setPosition(const sf::Vector2f& pos) { _relativePos = pos; }

	/**
	 * @brief 同步元件的全局位置
	 * @param parentPos 父元件的位置
	 */
	virtual void syncPosition(const sf::Vector2f& parentPos) { 
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
	 * @brief 檢查指定座標是否在元件範圍內
	 * @param pos 要檢查的座標
	 * @return bool 是否在範圍內
	 */
	bool containPos(const sf::Vector2f& pos) const {
		return (pos.x >= _globalPos.x && pos.x <= _globalPos.x + _size.x)
		&& (pos.y >= _globalPos.y && pos.y <= _globalPos.y + _size.y);
	}

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
	 * @brief 處理輸入事件
	 * @param event SFML事件，可為空
	 * @return bool 是否處理了事件
	 * @note 如果事件被處理，則返回 true，否則返回 false
	 */
	virtual bool handleEvent(const std::optional<sf::Event>& event) { return false; }
	
};