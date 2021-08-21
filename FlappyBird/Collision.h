#pragma once
#include <Definitions.h>
#include <SFML/Graphics.hpp>

class Collision
{
public:
	bool Intersect(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
};

