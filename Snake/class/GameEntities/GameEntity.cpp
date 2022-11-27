#include "GameEntity.h"

void GameEntity::setEntityPosition(int x, int y)
{
	this->m_sprite.setPosition(
		static_cast<float>(x), 
		static_cast<float>(y)
	);
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

sf::Sprite GameEntity::getEntitySprite() const noexcept
{
	return this->m_sprite;
}

const sf::IntRect GameEntity::getEntityTextureRect() const noexcept
{
	return this->getEntitySprite().getTextureRect();
}
