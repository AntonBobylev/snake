#include "Fruit.hpp"

Fruit::Fruit(Snake* snake)
	: m_snake(snake)
{ 
	this->setEntityTexture("resources/snake.png"); // it should be the same size
	this->setEntityColor(sf::Color(255, 0, 36));
	this->generateRandomPosition();
}

void Fruit::update() noexcept 
{ }

void Fruit::generateRandomPosition() noexcept
{
	while (true) {
		const GameEntity::Point randomPoint = this->getRandomPoint();

		bool fruitIsInSnake = this->isGeneratedPointInSnake(randomPoint);
		bool fruitIsOnSnakeLine = (randomPoint.x % config::SNAKE_TEXTURE_SIZE == 0 && randomPoint.y % config::SNAKE_TEXTURE_SIZE == 0);

		if (!fruitIsInSnake && fruitIsOnSnakeLine) {
			this->setEntityPosition(randomPoint.x, randomPoint.y);
			return;
		}
	}
}

GameEntity::Point Fruit::getEntityPosition() const noexcept
{
	sf::Vector2f spriteCoordinates = {this->m_sprite.getPosition()};

	return Point {
		static_cast<int>(spriteCoordinates.x),
		static_cast<int>(spriteCoordinates.y)
	};
}

GameEntity::Point Fruit::getRandomPoint(bool allPoints)
{
	GameEntity::Point point;

	int wWidth = config::WINDOW_WIDTH;
	int wHeight = config::WINDOW_HEIGHT;

	if (!allPoints) {
		const sf::IntRect fruitRect = this->getEntityTextureRect();

		wWidth = fruitRect.width - fruitRect.width;
		wHeight = fruitRect.height - fruitRect.height;
	}

	point.x = 1 + rand() % wWidth;
	point.y = 1 + rand() % wHeight;

	return point;
}

bool Fruit::isGeneratedPointInSnake(const Point& randomPoint)
{
	const Point* snakeParts = this->m_snake->getSnakePartsCoordinates();

	for (unsigned char i = 0; i < this->m_snake->getSnakeLength(); i++) {
		if (randomPoint.x == snakeParts[i].x
			&& randomPoint.y == snakeParts[i].y
		) {
			return true;
		}
	}

	return false;
}
