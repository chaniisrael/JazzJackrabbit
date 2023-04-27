#pragma once
#include "DinamicObject.h"
#include "Player.h"
class MonsterType :public DinamicObject
{
public:
	MonsterType(const std::string& name, const sf::Vector2f& location, float height, float width, Player& player);
	MonsterType() = default;
	~MonsterType() = default;
	virtual void move(sf::Time deltaTime) = 0;
	int getLifeS();
	void setLifeS(int num);
	int getLifeR();
	void setLifeR();
	bool canCollide();
	
protected:
	Player& m_player;
	int m_lifeS;
	int m_lifeR;
	sf::Clock m_collideClock;
};
