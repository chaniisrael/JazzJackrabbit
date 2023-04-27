#include "RegularMonster.h"

RegularMonster::RegularMonster( const sf::Vector2f& location, float height, float width, Player& player) : MonsterType("monsterR",location, height, width, player)
{
}

void RegularMonster::move(sf::Time deltaTime)
{
	int m_go = 0;
	int random;
	if (m_go == 0)
	{
		m_go = 100;
		random = rand() % 4+1; //range 1 to 4
		switch (random)
		{
		case PRESS_LEAFT:
			m_direction = sf::Vector2f(-100, 0);//left
			break;

		case PRESS_RIGHT:
			m_direction = sf::Vector2f(0, 100);//down
			break;

		case PRESS_UP:
			m_direction = sf::Vector2f(0, -80);//up
			break;

		case PRESS_DOWN:
			m_direction = sf::Vector2f(100, 0);//right
			break;
		}
	}
	m_go--;
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}

