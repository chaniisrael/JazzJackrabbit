#pragma once
#include "StaticObject.h"
#include "Factory.h"
class Dokar : public StaticObjet
{
public:
	Dokar( const sf::Vector2f& location, const float height, const float width);
	Dokar() = default;
	~Dokar() = default;

protected:

	static bool m_registerit;
};
inline bool Dokar::m_registerit = Factory::registerit("dokar",
	[](const sf::Vector2f& location, float height,  float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Dokar>(location,  height,  width); });

