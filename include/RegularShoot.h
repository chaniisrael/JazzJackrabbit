#pragma once
#include "ShootType.h"
#include "Factory.h"
#include "Resources.h"
class RegularShoot :public ShootType
{
public:
	RegularShoot( const sf::Vector2f& location, float height, float width);
	RegularShoot() = default;
	~RegularShoot() = default;
	virtual void move(sf::Time deltaTime)override;
	protected:
		static bool m_registerit;
};

inline bool RegularShoot::m_registerit = Factory::registeritShoot("shootR",
	[](const sf::Vector2f& location, float height, float width) -> std::unique_ptr<ShootType> { return std::make_unique<RegularShoot>(location, height, width); });

