#pragma once
#include "../GameEntity.h"

enum class Direction {
	RIGHT = 0,
	LEFT,
	DOWN,
	UP
};

const int16_t m_snakeMaxLength = 100;

class SnakeEntity : public GameEntity {
public:
	SnakeEntity();
	~SnakeEntity() {};

public:
	int16_t getSnakeDirection() const noexcept;
	Direction getSnakeDirectionEnum() const noexcept;
	void setSnakeDirection(Direction direction) noexcept;
	Point getEntityPosition() const noexcept;

	void update();

	void incrementLength() noexcept { this->m_snakeLength++; }
	int16_t getSnakeLength() const noexcept { return this->m_snakeLength; }

private:
	void moveSnakeParts();

public:
	Point m_snakeCoordinates[m_snakeMaxLength];

private:
	Direction m_direction;
	int16_t m_snakeLength;
};