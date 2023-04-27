#pragma once
#include "StaticObject.h"
#include "Factory.h"
class Door : public StaticObjet
{
public:
	Door( const sf::Vector2f& location, float height,  float width);
	Door()=default;
	~Door()= default;

private:
	static bool m_registerit;
};
inline bool Door::m_registerit = Factory::registerit("door",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Door>(location, height, width); });
