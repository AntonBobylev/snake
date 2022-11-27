#pragma once
#include "../SfmlWindow/config.hpp"
#include <SFML/Graphics.hpp>

class GameEntity
{
public:
	struct Point {
		int x = 0;
		int y = 0;
	};

public:
	virtual void update() = 0;

public:
	virtual Point getEntityPosition() const noexcept = 0 ;
	
public:
	void setEntityPosition(int x, int y);
	void setEntityTexture(const char* textureName);
	void setEntityColor(sf::Color color);

public:
	sf::Sprite getEntitySprite() const noexcept;
	const sf::IntRect getEntityTextureRect() const noexcept;

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};