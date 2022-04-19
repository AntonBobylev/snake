#pragma once
#include "../SfmlWindow/config.hpp"
#include <SFML/Graphics.hpp>

class GameEntity
{
public:
	struct Point {
		float x = 0;
		float y = 0;
	};
public:
	virtual void setEntityPosition(float width, float height);
	virtual void setEntityTexture(const char* textureName);
	virtual void setEntityColor(sf::Color color);
	sf::Sprite getEntitySprite() const noexcept { return this->m_sprite; }
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};