#pragma once
#include <SFML/Graphics.hpp>
#include "../GameEntities/SnakeEntity/SnakeEntity.hpp"
#include "../GameEntities/FruitEntity/FruitEntity.hpp"
#include "../PhysicsManager/PhysicsManager.hpp"
#include <Windows.h>

class SfmlWindow {
public:
	SfmlWindow();
	SfmlWindow(const char* appName);
	~SfmlWindow();

public:
	int mainLoop();

private:
	void update();

	bool windowOpened() const noexcept;
	void closeWindow();
	void clearWindow(sf::Color color);

	void init();

	void renderWindow();
	void renderEntities();
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

private:
	SnakeEntity m_snake;
	FruitEntity m_fruit;
	PhysicsManager m_physicsManager;
};