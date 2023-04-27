#pragma once
#include "ShootType.h"
#include "Factory.h"
class SpecielShoot : public ShootType
{
public:
	SpecielShoot( const sf::Vector2f& location, float height, float width);
	SpecielShoot() = default;
	~SpecielShoot() = default;
	virtual void move(sf::Time deltaTime)override;
protected:
	static bool m_registerit;
};
inline bool SpecielShoot::m_registerit = Factory::registeritShoot("shootR",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<ShootType> { return std::make_unique<SpecielShoot>(location, height, width); });

