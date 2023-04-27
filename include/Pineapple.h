#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include <memory>
class Pineapple : public StaticObjet
{
public:
	Pineapple( const sf::Vector2f& location, float height, float width);
	Pineapple() = default;
	~Pineapple() = default;
	// virtual void draw(sf::RenderWindow& window)override;

protected:
	//sf::Sprite m_sprite;
	static bool m_registerit;
};
inline bool Pineapple::m_registerit = Factory::registerit("pineapple",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Pineapple>(location, height, width); });
