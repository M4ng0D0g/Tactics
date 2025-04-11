#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class TextureManager {
private:
	TextureManager() {}
	~TextureManager() {}

	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> _textures;

public:
	static TextureManager& getInstance() {
		static TextureManager instance;
		return instance;
	}
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;

	bool loadTexture(const std::string& name, const std::string& filePath) {
		auto texture = std::shared_ptr<sf::Texture>();
		if(texture->loadFromFile(filePath)) return false;
		_textures[name] = texture;
		return true;
	}

	std::shared_ptr<sf::Texture> getTexture(const std::string& name) {
		auto it = _textures.find(name);
		if(it == _textures.end()) return nullptr;
		return it->second;
	}
};