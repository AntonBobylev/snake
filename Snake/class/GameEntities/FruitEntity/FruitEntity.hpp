#pragma once
#include "../GameEntity.h"
#include "../SnakeEntity/SnakeEntity.hpp"

class FruitEntity : public GameEntity {
public:
	FruitEntity();
	~FruitEntity() {};

public:
	void update() noexcept;
	void generateRandomPosition(SnakeEntity* snake) noexcept;
	Point getEntityPosition() const noexcept;
	bool isGenerationNeeded() const noexcept;

private:
	GameEntity::Point getRandomPoint();

private:
	Point m_fruitCoordinates;
	bool m_needToGeneratePosition;
};