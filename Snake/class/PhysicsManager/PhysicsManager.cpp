#include "PhysicsManager.hpp"

void PhysicsManager::checkSnakeCollisions(SnakeEntity* snake, FruitEntity* fruit)
{
	GameEntity::Point snakePosition = snake->getEntityPosition();
	GameEntity::Point fruitPosition = fruit->getEntityPosition();

	sf::Rect<int> snakeRect(snake->getEntitySprite().getTextureRect());
	snakeRect.left = snakePosition.x;
	snakeRect.top = snakePosition.y;

	sf::Rect<int> fruitRect(fruit->getEntitySprite().getTextureRect());
	fruitRect.left = fruitPosition.x;
	fruitRect.top = fruitPosition.y;

	if (snakeRect.intersects(fruitRect)) {
		snake->incrementLength();

		//TODO: Maybe decrement game speed ???

		fruit->generateRandomPosition(snake);
	}
}