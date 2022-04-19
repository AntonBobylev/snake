#include "SnakeEntity.hpp"
#include <iostream>

SnakeEntity::SnakeEntity()
	: m_direction(Direction::RIGHT)
	, m_snakeLength(1)
{
	this->setEntityTexture("resources/snake.png");
	this->setEntityPosition(0, 0);
	this->setEntityColor(sf::Color(255, 122, 0));
}

int16_t SnakeEntity::getSnakeDirection() const noexcept
{
	return static_cast<int16_t>(this->m_direction);
}

Direction SnakeEntity::getSnakeDirectionEnum() const noexcept
{
	return this->m_direction;
}

void SnakeEntity::setSnakeDirection(Direction direction) noexcept
{
	this->m_direction = direction;
}

GameEntity::Point SnakeEntity::getEntityPosition() const noexcept
{
	return this->m_snakeCoordinates[0];
}

void SnakeEntity::update()
{
	this->moveSnakeParts();

	switch (this->m_direction)
	{
	case Direction::RIGHT:
		this->m_snakeCoordinates[0].x += config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::LEFT:
		this->m_snakeCoordinates[0].x -= config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::DOWN:
		this->m_snakeCoordinates[0].y += config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::UP:
		this->m_snakeCoordinates[0].y -= config::SNAKE_TEXTURE_SIZE;
		break;
	default:
		break;
	}

	
}

void SnakeEntity::moveSnakeParts()
{
	for (int i = this->m_snakeLength; i > 0; i--) {
		this->m_snakeCoordinates[i].x = this->m_snakeCoordinates[i - 1].x;
		this->m_snakeCoordinates[i].y = this->m_snakeCoordinates[i - 1].y;
	}
}
