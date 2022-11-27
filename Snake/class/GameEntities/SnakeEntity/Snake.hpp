#pragma once
#include "../GameEntity.h"
#include "../SnakeEntity/Snake.hpp"

enum class Direction {
	RIGHT = 0,
	LEFT,
	DOWN,
	UP
};

class Snake : public GameEntity {
public:
	Snake();
	~Snake() {};

public:
	void update() noexcept;

public:
	void setSnakeDirection(Direction direction) noexcept;
	int16_t getSnakeDirection() const noexcept;

	Direction getSnakeDirectionEnum() const noexcept;

	Point getEntityPosition() const noexcept;

	const Point getSnakeHeadPosition() const noexcept;
	const Point* getSnakePartsCoordinates() const noexcept;

	int16_t getSnakeLength() const noexcept { return this->m_snakeLength; }

	void incrementLength() noexcept { this->m_snakeLength++; }

private:
	void moveSnakeParts();

public:
	Point m_snakePartsCoordinates[config::SNAKE_MAX_LENGTH];

private:
	Direction m_direction;
	int16_t m_snakeLength;
};
