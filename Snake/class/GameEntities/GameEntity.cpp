#include "GameEntity.h"

void GameEntity::setEntityPosition(float width, float height)
{
	this->m_sprite.setPosition(width, height);
}

void GameEntity::setEntityTexture(const char* textureName)
{
	this->m_texture.loadFromFile(textureName);
	this->m_sprite.setTexture(this->m_texture);
}

void GameEntity::setEntityColor(sf::Color color)
{
	this->m_sprite.setColor(color);
}
