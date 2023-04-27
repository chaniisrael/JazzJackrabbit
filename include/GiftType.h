#pragma once
#include "StaticObject.h"
#include "Resources.h"

#include <memory>
#include <SFML/Graphics.hpp>

class GiftType : public StaticObjet
{
public:
	GiftType(const sf::Vector2f& location, float height,  float width);
	GiftType() = default;
	~GiftType() = default;
	//virtual void draw(sf::RenderWindow& window)override;

protected:

};
