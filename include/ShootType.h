#pragma once
#include "DinamicObject.h"
class ShootType :public DinamicObject
{
public:
	ShootType(const std::string& name, const sf::Vector2f& location, float height, float width);
	ShootType() = default;
	~ShootType() = default;
	virtual void move(sf::Time deltaTime) = 0;

protected:

};
