#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include <memory>
class Disqualifications : public StaticObjet
{
public:
	Disqualifications( const sf::Vector2f& location, const float height, const float width);
	Disqualifications() = default;
	
protected:
	static bool m_registerit;
	
};
inline bool Disqualifications::m_registerit = Factory::registerit("Disqualifications",
	[](const sf::Vector2f& location, float height,  float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Disqualifications>(location, height,  width); });

