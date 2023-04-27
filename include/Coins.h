#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Factory.h"
#include <memory>
class Coins : public StaticObjet
{
public:
	Coins( const sf::Vector2f& location, float height,  float width);
	Coins() = default;
	


protected:
	static bool m_registerit;

};
inline bool Coins::m_registerit = Factory::registerit("coin",
	[](const sf::Vector2f& location, float height,  float width) -> std::unique_ptr<StaticObjet> {std::cout << "QQQQ"; return std::make_unique<Coins>(location,  height,  width); });
