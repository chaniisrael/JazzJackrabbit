#include "DinamicObject.h"
#include <iostream>

DinamicObject::DinamicObject(const std::string& name, const sf::Vector2f& location, float height, float width) : GameObject(name, location,  height,  width), m_startPosition(location), m_lastPosition(location)
{
}

//--------------------------------------------------------------------------------------------------------------
void DinamicObject::setLastPosition()
{
	m_lastPosition = m_sprite.getPosition();
}
//--------------------------------------------------------------------------------------------------------------
void DinamicObject::getStartPosition()
{
	m_sprite.setPosition(m_startPosition);
}
void DinamicObject::calculateSpeed(sf::Vector2f& nextDirection, int speed)
{
	nextDirection.x *= speed;
	nextDirection.y *= speed;
}
//--------------------------------------------------------------------------------------------------------------
void DinamicObject::isCloseEnoughToAxis(sf::Time deltaTime)
{
	if (std::abs(m_sprite.getPosition().x - m_positionDestination.x) <= EPSILON &&
		std::abs(m_sprite.getPosition().y - m_positionDestination.y) <= EPSILON)
	{
		m_direction = m_nextDirection;
		if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
			m_sprite.move(m_direction * deltaTime.asSeconds());
	}
}

int DinamicObject::getDirection()
{
	if (m_direction.x == 0 && m_direction.y == 0)
		return Default;
	else if (m_direction.x < 0)
		return PRESS_LEAFT;
	else if (m_direction.x > 0)
		return PRESS_RIGHT;
	else if (m_direction.y < 0)
		return PRESS_UP;
	else if (m_direction.y > 0)
		return PRESS_DOWN;
}

//--------------------------------------------------------------------------------------------------------------
void DinamicObject::setDirection(sf::Vector2f direction)
{
	std::cout <<direction.x<< direction.y<<'\n';
	m_direction = direction;
}
bool DinamicObject::isOutOfLimits(const sf::Vector2f& destination)
{
	return(destination.x >= 0 && destination.x + m_sprite.getGlobalBounds().width <= HIGHT_OF_WINDOW &&
		destination.y >= 0 && destination.y + m_sprite.getGlobalBounds().height <= WIDTH_OF_BOARD);
}

void DinamicObject::setLocation()
{
	m_sprite.setPosition(m_lastPosition);
}
