#pragma once

#include <unordered_map>
#include <string>
#include <functional>

class UIBinder {
private:
	std::unordered_map<std::string, std::function<std::string()>> _bindings;

public:
	UIBinder() = default;

	void bind(const std::string& key, std::function<std::string()> getter) {
		_bindings[key] = getter;
	}

	std::string getValue(const std::string& key) {
		if(_bindings.find(key) == _bindings.end()) return "";
		return _bindings[key]();
	}
};

#endif