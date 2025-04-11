#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <memory>
#include <optional>
#include <iostream>
#include <vector>

#include "ui/screens/TestScreen.h"
#include "ui/Window.h"

int main() {
	std::cout << "Hello, World!" << std::endl;

	Window& window = Window::getInstance({1920, 1008}, "Test", 60);

	TestScreen testScreen({1920, 1008});

	window.setScreen(testScreen.getScreen());
	window.open();

	return 0;
}
