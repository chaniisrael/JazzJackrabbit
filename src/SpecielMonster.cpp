#include "SpecielMonster.h"

SpecielMonster::SpecielMonster( const sf::Vector2f& location, float height, float width, Player& player) : MonsterType("monsterS",location,  height,  width, player)
{
}

void SpecielMonster::move(sf::Time deltaTime)
{

	auto destination = sf::Vector2f();//���� ������
	float distance;//����� ���� ������ ����� 
	sf::Vector2f  wantedLocation;//���� ����� 
	float minDistance = WIDTH_OF_BOARD + HIGHT_OF_WINDOW;//������ ����� �����---�������� ����
	for (int direction = 0; direction < 4; direction++)
	{
		wantedLocation = directionVector(direction);//����� ���� �����
		destination = (wantedLocation + m_positionDestination);//������ ������ ����� ���� 
		distance = distances(destination, m_player.getPosition());//����� ����� 
		if (distance < minDistance)//����
		{
			minDistance = distance;
			m_direction = directionVector(direction);//����� �� �ENUM ������ �����
		}
	}
	isCloseEnoughToAxis(deltaTime);
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}


sf::Vector2f SpecielMonster::directionVector(int direction)
{
	switch (direction)
	{
	case PRESS_LEAFT:
		return { -40,0 };
		break;
	case PRESS_DOWN:
		return { 0, 40 };
		break;
	case PRESS_UP:
		return { 0, -40 };
		break;
	case PRESS_RIGHT://����� �� ������ �����
		return{ 40, 0 };
		break;
	}
	//return  { -40,0 };
}

float SpecielMonster::distances(sf::Vector2f destination, sf::Vector2f location)
{

	return abs(destination.x - location.x) + abs(destination.y - location.y);
}

float SpecielMonster::manhattan�Distance(sf::Vector2f possibleDestigntion)
{
	return (std::abs(possibleDestigntion.x - (m_player.getPosition()).x) +
		std::abs(possibleDestigntion.y - (m_player.getPosition()).y));

}


