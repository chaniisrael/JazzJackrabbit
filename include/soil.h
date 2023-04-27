#pragma once
#include "StaticObject.h"
#include "Factory.h"
class soil : public StaticObjet
{
public:
	soil( const sf::Vector2f& location, const float height, const float width) ;
	soil() = default;
	~soil() = default;
	//virtual void draw(sf::RenderWindow& window)override;
protected:
	//sf::Sprite m_sprite;
	static bool m_registerit;
};
inline bool soil::m_registerit = Factory::registerit("soil",
	[](const sf::Vector2f& location, float height,  float width) -> std::unique_ptr<StaticObjet> { return std::make_unique<soil>(location,  height,  width); });

