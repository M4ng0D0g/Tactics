#ifndef CONSOLEWINDOW_H
#define CONSOLEWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>

// ***************************************************************************/

class ConsoleWindow {
private:
	sf::RenderWindow _window;
	sf::Font _font;
	sf::Text _inputText;
	sf::Text _outputText;
	std::string _inputBuffer;
	std::vector<std::string> _outputLines;

public:
	ConsoleWindow();

	void run();
	void handleInput(const sf::Event::KeyPressed*);
	void processCommand(const std::string&);
	void updateOutputText();
	void draw();
};

#endif