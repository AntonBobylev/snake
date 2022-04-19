#include "SnakeEntity.hpp"

SnakeEntity::SnakeEntity()
	: m_direction(Direction::RIGHT)
	, m_snakeLength(1)
{}

int16_t SnakeEntity::getSnakeDirection() const noexcept
{
	return static_cast<int16_t>(this->m_direction);
}

void SnakeEntity::setSnakeDirection(Direction direction) noexcept
{
	this->m_direction = direction;
}

void SnakeEntity::update()
{
	this->moveSnakeParts();

	switch (this->m_direction)
	{
	case Direction::RIGHT:
		this->m_snakeCoordinates[0].x += config::SNAKE_STEP;
		break;
	case Direction::LEFT:
		this->m_snakeCoordinates[0].x -= config::SNAKE_STEP;
		break;
	case Direction::DOWN:
		this->m_snakeCoordinates[0].y += config::SNAKE_STEP;
		break;
	case Direction::UP:
		this->m_snakeCoordinates[0].y -= config::SNAKE_STEP;
		break;
	default:
		break;
	}

	for (int i = 0; i < this->m_snakeLength; i++) {
		this->m_sprite.setPosition(
			this->m_snakeCoordinates[i].x,
			this->m_snakeCoordinates[i].y
		);
	}
}

void SnakeEntity::moveSnakeParts()
{
	for (int i = this->m_snakeLength; i > 0; i--) {
		this->m_snakeCoordinates[i].x = this->m_snakeCoordinates[i - 1].x;
		this->m_snakeCoordinates[i].y = this->m_snakeCoordinates[i - 1].y;
	}
}
