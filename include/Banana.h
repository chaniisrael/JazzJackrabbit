#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include <memory>
class Banana : public StaticObjet
{
public:
	Banana( const sf::Vector2f& location, float height, float width);
	Banana() = default;
	~Banana() = default;
	

protected:

	static bool m_registerit;
};
inline bool Banana::m_registerit = Factory::registerit("banana",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Banana>(location, height, width); });
