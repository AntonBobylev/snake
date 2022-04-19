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
	void setSnakeDirection(Direction direction) noexcept;

	void update();

private:
	void moveSnakeParts();

private:
	Direction m_direction;
	Point m_snakeCoordinates[m_snakeMaxLength];
	int16_t m_snakeLength;
};