#pragma once
#include "GameObject.h"
#include "const.h"
class DinamicObject : public GameObject
{
public:
	DinamicObject(const std::string& name, const sf::Vector2f& location, float height, float width);
	DinamicObject() = default;
	~DinamicObject() = default;
	void setLastPosition();
	void getStartPosition();
	void calculateSpeed(sf::Vector2f& nextDirection, int speed);
	void isCloseEnoughToAxis(sf::Time deltaTime);
	//sf::Vector2i checkCollisionByDirection();
	int getDirection();
	void setDirection(sf::Vector2f direction);
	bool isOutOfLimits(const sf::Vector2f& destination);

	virtual void move(sf::Time deltaTime) = 0;
	void setLocation();
	sf::Vector2f getLastPosition() { return m_lastPosition; };
	void setPosition(sf::Vector2f position) { m_sprite.setPosition(position); };

protected:
	sf::Vector2f m_direction;
	sf::Vector2f m_startPosition;
	sf::Vector2f m_positionDestination; //מיקום  היעד
	sf::Vector2f m_nextDirection; //כיוון הבא
	sf::Vector2f m_lastPosition; 

};

