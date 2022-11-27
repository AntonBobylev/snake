#pragma once
#include "../GameEntities/SnakeEntity/Snake.hpp"
#include "../GameEntities/FruitEntity/Fruit.hpp"

class PhysicsManager {
public:
	PhysicsManager() {}
	~PhysicsManager() {}

public:
	void checkSnakeCollisions(Snake* snake, Fruit* fruit);

private:
	void checkSnakeIntersectsFruit(Snake* snake, Fruit* fruit);

private:
	template<typename T>
	bool isRectIntersectsRect(const T& first, const T& second);
};
