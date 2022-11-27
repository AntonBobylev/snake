#include "Snake.hpp"
#include <iostream>

Snake::Snake()
	: m_direction(Direction::RIGHT)
	, m_snakeLength(1)
{
	this->setEntityTexture("resources/snake.png");
	this->setEntityPosition(0, 0);
	this->setEntityColor(sf::Color(255, 122, 0));
}

int16_t Snake::getSnakeDirection() const noexcept
{
	return static_cast<int16_t>(this->m_direction);
}

Direction Snake::getSnakeDirectionEnum() const noexcept
{
	return this->m_direction;
}

void Snake::setSnakeDirection(Direction direction) noexcept
{
	this->m_direction = direction;
}

GameEntity::Point Snake::getEntityPosition() const noexcept
{
	return this->getSnakeHeadPosition();
}

const GameEntity::Point Snake::getSnakeHeadPosition() const noexcept
{
	return this->m_snakePartsCoordinates[0];
}

const GameEntity::Point* Snake::getSnakePartsCoordinates() const noexcept
{
	return this->m_snakePartsCoordinates;
}

void Snake::update() noexcept
{
	this->moveSnakeParts();

	switch (this->m_direction)
	{
	case Direction::RIGHT:
		this->m_snakePartsCoordinates[0].x += config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::LEFT:
		this->m_snakePartsCoordinates[0].x -= config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::DOWN:
		this->m_snakePartsCoordinates[0].y += config::SNAKE_TEXTURE_SIZE;
		break;
	case Direction::UP:
		this->m_snakePartsCoordinates[0].y -= config::SNAKE_TEXTURE_SIZE;
		break;
	default:
		break;
	}
}

void Snake::moveSnakeParts()
{
	for (int i = this->m_snakeLength; i > 0; i--) {
		this->m_snakePartsCoordinates[i].x = this->m_snakePartsCoordinates[i - 1].x;
		this->m_snakePartsCoordinates[i].y = this->m_snakePartsCoordinates[i - 1].y;
	}
}
