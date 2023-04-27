#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <memory>
class StaticObjet : public GameObject
{
public:
	StaticObjet(const std::string& name, const sf::Vector2f& location, float height,  float width);
    StaticObjet() = default;
	~StaticObjet() = default;
protected:

};

