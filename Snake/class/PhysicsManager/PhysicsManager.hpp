#pragma once
#include "../GameEntities/SnakeEntity/SnakeEntity.hpp"
#include "../GameEntities/FruitEntity/FruitEntity.hpp"

class PhysicsManager {
public:
	PhysicsManager() {}
	~PhysicsManager() {}

public:
	void checkSnakeCollisions(SnakeEntity* snake, FruitEntity* fruit);
};