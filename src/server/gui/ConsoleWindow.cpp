#include "gui/ConsoleWindow.h"
#include "connection/Server.h"

#include <optional>
#include <sstream>
#include <iostream>
#include <ft2build.h>

ConsoleWindow::ConsoleWindow()
: _window(sf::VideoMode({600, 400}), "Server Console"), _inputText(_font), _outputText(_font) {
	if (!_font.openFromFile("../assets/fonts/NotoSans-Regular.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	_inputText.setCharacterSize(20);
	_inputText.setFillColor(sf::Color::White);
	_inputText.setPosition({10, 365});

	_outputText.setCharacterSize(18);
	_outputText.setFillColor(sf::Color::White);
	_outputText.setPosition({10, 10});

	_window.setFramerateLimit(60);
}

void ConsoleWindow::run() {
	while(_window.isOpen()) {
		while(const std::optional event = _window.pollEvent()) {
			if(event->is<sf::Event::Closed>()) {
				_window.close();
				Server::getInstance().shutdownServer();
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				handleInput(keyPressed);
			}
		}
		_window.clear(sf::Color::Black);
		draw();
		_window.display();
	}
}

void ConsoleWindow::handleInput(const sf::Event::KeyPressed* keyPressed) {
	switch(keyPressed->scancode) {
		case sf::Keyboard::Scancode::Backspace:
			if(!_inputBuffer.empty()) _inputBuffer.pop_back();
			break;

		case sf::Keyboard::Scancode::Enter:
			processCommand(_inputBuffer);
			_inputBuffer.clear();
			break;

		default:
			sf::Keyboard::Key code = keyPressed->code;
			if(code >= sf::Keyboard::Key::A && code <= sf::Keyboard::Key::Z) {
				char c = 'A' + (static_cast<int>(code) - static_cast<int>(sf::Keyboard::Key::A));
				_inputBuffer += c;
			}
			else if(code >= sf::Keyboard::Key::Num0 && code <= sf::Keyboard::Key::Num9) {
				char c = '0' + (static_cast<int>(code) - static_cast<int>(sf::Keyboard::Key::Num0));
				_inputBuffer += c;
			}
			break;
	}
	_inputText.setString("> " + _inputBuffer);
}

void ConsoleWindow::processCommand(const std::string& command) {
	std::stringstream sStream;
	sStream << "You entered: " << command;
	_outputLines.push_back(sStream.str());

	if(_outputLines.size() > 10) _outputLines.erase(_outputLines.begin());
	updateOutputText();
}

void ConsoleWindow::updateOutputText() {
	std::string output;
	for(const auto& line : _outputLines) {
		output += line + "\n";
	}
	_outputText.setString(output);
}

void ConsoleWindow::draw() {
	_window.draw(_inputText);
	_window.draw(_outputText);
}