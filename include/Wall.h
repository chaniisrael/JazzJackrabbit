#pragma once
#include "StaticObject.h"
#include "Factory.h"
#include <memory>
class Wall : public StaticObjet
{
public:
	Wall( const sf::Vector2f& location, float height,  float width);
	Wall() = default;
	~Wall() = default;
	// virtual void draw(sf::RenderWindow& window)override;

protected:
	//sf::Sprite m_sprite;
	static bool m_registerit;
};
inline bool Wall::m_registerit = Factory::registerit("wall",
	[](const sf::Vector2f& location, float height,  float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<Wall>(location,  height,  width); });
