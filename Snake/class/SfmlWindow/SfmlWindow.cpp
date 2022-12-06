#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(const char* appName)
	:m_windowWidth(config::WINDOW_WIDTH)
	,m_windowHeight(config::WINDOW_HEIGHT)
	,m_window(sf::VideoMode(config::WINDOW_WIDTH, config::WINDOW_HEIGHT), appName)
	,m_event()
	,m_snake()
	,m_fruit(&this->m_snake)
	,m_physicsManager()
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
	this->m_fruit.update();
	this->m_physicsManager.checkSnakeCollisions(&this->m_snake, &this->m_fruit);
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
	this->m_window.clear(color);
}

void SfmlWindow::init()
{
	this->m_defaultWindowColor = sf::Color(26, 28, 36);
	srand(NULL);

	sf::Image icon;
	if (icon.loadFromFile(config::APPLICATION_ICON_PATH)) {
		this->m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
}

void SfmlWindow::renderWindow()
{
	this->clearWindow(this->m_defaultWindowColor);
	this->renderEntities();
	this->m_window.display();

	Sleep(250); // TODO: remove it
}

void SfmlWindow::renderEntities()
{
	//Snake
	for (int i = 0; i < this->m_snake.getSnakeLength(); i++) {
		this->m_snake.setEntityPosition(
			this->m_snake.m_snakePartsCoordinates[i].x ,
			this->m_snake.m_snakePartsCoordinates[i].y
		);
		this->m_window.draw(this->m_snake.getEntitySprite());
	}
	
	//Fruit
	this->m_window.draw(this->m_fruit.getEntitySprite());
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
			if (this->m_snake.getSnakeDirectionEnum() != Direction::LEFT) {
				this->m_snake.setSnakeDirection(Direction::RIGHT);
			}
			break;
		case sf::Keyboard::Left:
			if (this->m_snake.getSnakeDirectionEnum() != Direction::RIGHT) {
				this->m_snake.setSnakeDirection(Direction::LEFT);
			}
			break;
		case sf::Keyboard::Down:
			if (this->m_snake.getSnakeDirectionEnum() != Direction::UP) {
				this->m_snake.setSnakeDirection(Direction::DOWN);
			}
			break;
		case sf::Keyboard::Up:
			if (this->m_snake.getSnakeDirectionEnum() != Direction::DOWN) {
				this->m_snake.setSnakeDirection(Direction::UP);
			}
			break;
		default:
			break;
		}
	}
}

void SfmlWindow::handleLeftMouseReleased()
{ }
