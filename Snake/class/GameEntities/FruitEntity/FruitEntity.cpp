#include "FruitEntity.hpp"

FruitEntity::FruitEntity()
	: m_needToGeneratePosition(true)
{ 
	this->setEntityTexture("resources/snake.png"); // it should be the same size
	this->setEntityPosition(this->m_fruitCoordinates.x, this->m_fruitCoordinates.y);
	this->setEntityColor(sf::Color(255, 0, 36));
}

void FruitEntity::update() noexcept {

}

void FruitEntity::generateRandomPosition(SnakeEntity* snake) noexcept
{
	this->m_needToGeneratePosition = true;
	GameEntity::Point snakePosition = snake->getEntityPosition();
	

	while (this->m_needToGeneratePosition) {
		GameEntity::Point randomPoint = this->getRandomPoint();

		// Разбиваем карту на 10 частей
		for (int i = 0; i < 9; i++) {
			if (randomPoint.x <= (i + 1) * config::SNAKE_TEXTURE_SIZE && randomPoint.x > i * config::SNAKE_TEXTURE_SIZE) {
				randomPoint.x = (i + 1) * config::SNAKE_TEXTURE_SIZE;
			}
			if (randomPoint.y <= (i + 1) * config::SNAKE_TEXTURE_SIZE && randomPoint.y > i * config::SNAKE_TEXTURE_SIZE) {
				randomPoint.y = (i + 1) * config::SNAKE_TEXTURE_SIZE;
			}
		}


		for (int i = 0; i < snake->getSnakeLength(); i++) {
			if (randomPoint.x == snakePosition.x && randomPoint.y == snakePosition.y) {
				break;
			}
			else if ((randomPoint.x != snake->m_snakeCoordinates[i].x || randomPoint.x != snake->m_snakeCoordinates[i].x) && i == snake->getSnakeLength() - 1)
			{
				this->m_needToGeneratePosition = false;
				this->m_fruitCoordinates = randomPoint;
				this->setEntityPosition(randomPoint.x, randomPoint.y);
				break;
			}
		}
	}
}

GameEntity::Point FruitEntity::getEntityPosition() const noexcept
{
	return this->m_fruitCoordinates;
}

bool FruitEntity::isGenerationNeeded() const noexcept
{
	return this->m_needToGeneratePosition;
}

GameEntity::Point FruitEntity::getRandomPoint()
{
	GameEntity::Point point;
	int wWidth = config::WINDOW_WIDTH;
	int wHeight = config::WINDOW_HEIGHT;

	point.x = static_cast<float>(1 + rand() % wWidth);
	point.y = static_cast<float>(1 + rand() % wWidth);

	return point;
}
