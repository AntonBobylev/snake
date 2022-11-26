#include "PhysicsManager.hpp"

void PhysicsManager::checkSnakeCollisions(SnakeEntity* snake, FruitEntity* fruit)
{
	GameEntity::Point snakePosition = snake->getEntityPosition();
	GameEntity::Point fruitPosition = fruit->getEntityPosition();

	sf::Rect<int> snakeRect(snake->getEntitySprite().getTextureRect());

	// TODO: refactoring is needed. static_cast should be removed
	snakeRect.left = static_cast<int>(snakePosition.x);
	snakeRect.top = static_cast<int>(snakePosition.y);

	sf::Rect<int> fruitRect(fruit->getEntitySprite().getTextureRect());

	// TODO: refactoring is needed. static_cast should be removed
	fruitRect.left = static_cast<int>(fruitPosition.x);
	fruitRect.top = static_cast<int>(fruitPosition.y);

	if (snakeRect.intersects(fruitRect)) {
		snake->incrementLength();

		//TODO: Maybe decrement game speed ???

		fruit->generateRandomPosition(snake);
	}
}