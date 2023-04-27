#pragma once
#include "MonsterType.h"
#include "Factory.h"
class SpecielMonster : public MonsterType
{
public:
	SpecielMonster( const sf::Vector2f& location, float height, float width,Player& player);
	SpecielMonster() = default;
	~SpecielMonster() = default;
	virtual void move(sf::Time deltaTime)override;
	float manhattanÉDistance(sf::Vector2f possibleDestigntion);
	sf::Vector2f directionVector(int direction);
	float distances(sf::Vector2f destination, sf::Vector2f location);
protected:
	static bool m_registerit;
	
};
inline bool SpecielMonster::m_registerit = Factory::registeritMonster("monsterS",
	[](const sf::Vector2f& location, float height, float width,Player& player) ->std::unique_ptr<MonsterType> { return std::cout << "open22", std::make_unique<SpecielMonster>(location, height, width, player); });
