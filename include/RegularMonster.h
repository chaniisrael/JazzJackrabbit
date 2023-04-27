#pragma once
#include "MonsterType.h"
#include "Factory.h"
class RegularMonster :public MonsterType
{
public:
	RegularMonster( const sf::Vector2f& location, float height, float width, Player& player);
	RegularMonster() = default;
	~RegularMonster() = default;
	virtual void move(sf::Time deltaTime)override;
protected:
	static bool m_registerit;
};
inline bool RegularMonster::m_registerit = Factory::registeritMonster("monsterR",
	[](const sf::Vector2f& location, float height , float width, Player& player) -> std::unique_ptr<MonsterType> { return std::cout<<"open21", std::make_unique<RegularMonster>(location,  height,  width, player); });
