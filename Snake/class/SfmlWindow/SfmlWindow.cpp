#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow()
	: m_windowWidth(500)
	, m_windowHeight(500)
	, m_window(sf::VideoMode(500, 500), "App")
	, m_event()
	, m_snake()
{
	this->init();
}

SfmlWindow::SfmlWindow(int16_t width, int16_t height, const char* appName)
	:m_windowWidth(width)
	,m_windowHeight(height)
	,m_window(sf::VideoMode(width, height), appName)
	,m_event()
	,m_snake()
{
	this->init();
}

SfmlWindow::~SfmlWindow()
{ }

int SfmlWindow::mainLoop()
{
	while (this->windowOpened()) {
		this->handleWindowEvents();
		this->update();
		this->renderWindow();
	}

	this->closeWindow();
	return 0;
}

void SfmlWindow::update()
{
	this->m_snake.update();
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
	
	this->m_snake.setEntityTexture("resources/square.png");
	this->m_snake.setEntityPosition(0, 0);
	this->m_snake.setEntityColor(sf::Color(255, 122,0));

}

void SfmlWindow::renderWindow()
{
	this->clearWindow(this->m_defaultWindowColor);
	this->m_window.draw(this->m_snake.getEntitySprite());
	this->m_window.display();
	//Sleep(500);
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
			this->m_snake.setSnakeDirection(Direction::RIGHT);
			break;
		case sf::Keyboard::Left:
			this->m_snake.setSnakeDirection(Direction::LEFT);
			break;
		case sf::Keyboard::Down:
			this->m_snake.setSnakeDirection(Direction::DOWN);
			break;
		case sf::Keyboard::Up:
			this->m_snake.setSnakeDirection(Direction::UP);
			break;
		default:
			break;
		}
	}
}

void SfmlWindow::handleLeftMouseReleased()
{

}
