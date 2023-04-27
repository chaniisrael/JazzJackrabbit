#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include <memory>
class Keyy : public StaticObjet
{
public:
	Keyy( const sf::Vector2f& location, float height, float width);
	Keyy() = default;
	~Keyy() = default;

private:
	static bool m_registerit;
};
inline bool Keyy::m_registerit = Factory::registerit("key",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Keyy>(location, height, width); });