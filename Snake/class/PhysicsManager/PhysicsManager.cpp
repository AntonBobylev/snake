#include "PhysicsManager.hpp"

void PhysicsManager::checkSnakeCollisions(Snake* snake, Fruit* fruit)
{
	checkSnakeIntersectsFruit(snake, fruit);

	// Paste new collisions tests here in future
	// Like: snake parts collissions, snake head and border of the screen collisions
}

void PhysicsManager::checkSnakeIntersectsFruit(Snake* snake, Fruit* fruit)
{
	GameEntity::Point snakePosition = snake->getEntityPosition();
	GameEntity::Point fruitPosition = fruit->getEntityPosition();

	sf::IntRect snakeRect = snake->getEntityTextureRect();

	snakeRect.left = snakePosition.x;
	snakeRect.top = snakePosition.y;

	sf::IntRect fruitRect = fruit->getEntityTextureRect();

	fruitRect.left = fruitPosition.x;
	fruitRect.top = fruitPosition.y;

	if (this->isRectIntersectsRect(snakeRect, fruitRect)) {
		snake->incrementLength();

		fruit->generateRandomPosition();
	}
}

template<typename T>
inline bool PhysicsManager::isRectIntersectsRect(const T& first, const T& second)
{
	return first.intersects(second);
}
