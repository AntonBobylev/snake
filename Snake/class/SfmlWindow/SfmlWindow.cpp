#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow() 
	: m_windowWidth(500)
	, m_windowHeight(500)
	, m_window(sf::VideoMode(500, 500), "App")
	, m_event()
{
	this->init();
}

SfmlWindow::SfmlWindow(int16_t width, int16_t height, const char* appName)
	:m_windowWidth(width)
	,m_windowHeight(height)
	,m_window(sf::VideoMode(width, height), appName)
	,m_event()
{
	this->init();
}

SfmlWindow::~SfmlWindow()
{ }

int SfmlWindow::mainLoop()
{
	while (this->windowOpened()) {
		this->handleWindowEvents();
		this->renderWindow();
	}

	this->closeWindow();
	return 0;
}

bool SfmlWindow::windowOpened() const noexcept
{
	return m_window.isOpen();
}

void SfmlWindow::closeWindow()
{
	if (this->windowOpened()) {
		this->m_window.close();
	}
}

void SfmlWindow::clearWindow(sf::Color color)
{
	this->m_window.clear(color); // TODO: replace to class member
}

void SfmlWindow::init()
{
	this->m_defaultWindowColor = sf::Color(26, 28, 36);
}

void SfmlWindow::renderWindow()
{
	this->clearWindow(this->m_defaultWindowColor);
	this->m_window.display();
}

void SfmlWindow::handleWindowEvents()
{
	while (this->m_window.pollEvent(this->m_event)) {
		this->eventClose();
		this->eventMouse();
		this->eventKeyboard();
	}
}

void SfmlWindow::eventClose()
{
	if (this->m_event.type == sf::Event::Closed) {
		this->closeWindow();
	}
}

void SfmlWindow::eventMouse()
{
	if (this->m_event.type == sf::Event::MouseButtonReleased) {
		if (this->m_event.key.code == sf::Mouse::Left) {
			this->handleLeftMouseReleased();
		}
	}
}

void SfmlWindow::eventKeyboard()
{
	if (this->m_event.type == sf::Event::KeyPressed) {
		switch (this->m_event.key.code)
		{
		case sf::Keyboard::Right:
			// right arrow logic
			break;
		case sf::Keyboard::Left:
			// left arrow logic
			break;
		case sf::Keyboard::Down:
			// down arrow logic
			break;
		case sf::Keyboard::Up:
			// up arrow logic
			break;
		default:
			break;
		}
	}
}

void SfmlWindow::handleLeftMouseReleased()
{

}
