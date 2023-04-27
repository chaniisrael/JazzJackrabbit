#include "MonsterType.h"
#include <iostream>

MonsterType::MonsterType(const std::string& name, const sf::Vector2f& location, float height, float width, Player& player) : DinamicObject(name,  location, height, width), m_player(player), m_lifeS(10)
{
	std::cout << "open23";

}

int MonsterType::getLifeS()
{
	return m_lifeS;
}

void MonsterType::setLifeS(int num)
{
	m_lifeS += num;
}

int MonsterType::getLifeR()
{
	return m_lifeR;
}

bool MonsterType::canCollide()
{
	if (m_collideClock.getElapsedTime().asSeconds() > 4)
	{
		m_collideClock.restart();
		return true;
	}
	return false;
}
