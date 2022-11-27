#pragma once
#include "../GameEntity.h"
#include "../SnakeEntity/Snake.hpp"

class Fruit : public GameEntity {
public:
	Fruit() = delete;
	Fruit(Snake* snake);
	~Fruit() {};

public:
	void update() noexcept;

public:
	Point getEntityPosition() const noexcept;
	void generateRandomPosition() noexcept;

private:
	GameEntity::Point getRandomPoint(bool allPoints = true);
	bool isGeneratedPointInSnake(const Point& randomPoint);

private:
	Snake* m_snake;
};
