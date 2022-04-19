#pragma once
#include <SFML/Graphics.hpp>

class SfmlWindow {
public:
	SfmlWindow();
	SfmlWindow(int16_t width, int16_t height, const char* appName);
	~SfmlWindow();

public:
	int mainLoop();

private:
	bool windowOpened() const noexcept;
	void closeWindow();
	void clearWindow(sf::Color color);

	void init();

	void renderWindow();
	void handleWindowEvents();

	
private:
	// Events
	
	void eventClose(); // handle to close window
	void eventMouse(); // handle of mouse events
	void eventKeyboard(); // handle of keyboard events

private:
	void handleLeftMouseReleased();

private:
	sf::RenderWindow m_window;
	sf::Event m_event;

	int16_t m_windowWidth;
	int16_t m_windowHeight;

	sf::Color m_defaultWindowColor;
};