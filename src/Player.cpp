#include "Player.h"
#include <iostream>
#include <Factory.h>

Player::Player():  m_life(TOTAL_LIFE),m_Disqualifications(DISQUALIFICATIONS), m_state(std::make_unique<StandingState>()), m_coins(0), m_Key(0), m_fruit(0)
{
}

void Player::setPlayer(const std::string& name, const sf::Vector2f& location, int width, int height, int time, int key, sf::Vector2f direction)
{
	
	setObjet("player",location, width, height);
	m_startPosition = location;
	m_direction = direction;
	m_location = location;
	m_Key = key;
	m_time = time;
	m_timeeee = time;
}
void Player::handleInput(Input input)
{
	unique_ptr<State> state_ = m_state->handleInput(input);
	if (state_)
	{
		m_state = std::move(state_);
		m_state->enter(*this);
	}
}
void Player::handleEvent(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Left:
		handleInput(PRESS_LEAFT);
		break;
	case sf::Keyboard::Key::Right:
		handleInput(PRESS_RIGHT);
		break;
	case sf::Keyboard::Key::Up:
		handleInput(PRESS_UP);
		break;
	case sf::Keyboard::Key::Space:
		handleInput(PRESS_STOP);
		break;
	case sf::Keyboard::Key::Enter:
		m_shoot.emplace_back(Factory::createShoot("regularShoot", m_sprite.getPosition(), 50, 50));
	/*case sf::Keyboard::Key::Down:
		handleInput(PRESS_FALL);
		break;*/
	}

}
void Player::enter()
{
	m_state->enter(*this);
}
//-----------------------------------------------------------------------
sf::Vector2f Player::getPosition() const
{
	return m_sprite.getPosition();
}
//--------------------------------------------------------------------------------------------
void Player::move(sf::Time deltaTime)
{
	isCloseEnoughToAxis(deltaTime);
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}
void Player::shoot(sf::Time deltaTime)
{
	for (const auto& shoot : m_shoot)
	{
		shoot.get()->setDirection(m_direction);
		//shoot.get()->setLastPosition();
		shoot->move(deltaTime);
	}
}
void Player::drawShoot(sf::RenderWindow& window)
{
	for (const auto& shoot : m_shoot)
	{


		shoot->setPosition(shoot->getLastPosition());
		//m_sprite.setPosition(m_lastPosition);
		shoot->draw(window);
	}
}
//-----------------------------------------------------------------------------------------------


int Player::getLife()
{
	return m_life;
}

void Player::setLife(int num)
{
	m_life += (num);
}

int Player::getDisqualifications()
{
	return m_Disqualifications;
}

void Player::setDisqualifications(int num)
{
	if (m_Disqualifications < 1)
	{
		setLife(-1);
		m_Disqualifications = DISQUALIFICATIONS;
	}
	else
	m_Disqualifications += num;
}

int Player::getCoins()
{
	return m_coins;
}

void Player::setCoins(int num)
{
	m_coins += num;
}

int Player::getTime()
{
	return m_time;
}

void Player::setTime(int num)
{
	m_time += num;
}

int Player::getKey()
{
	return m_Key;
}

void Player::setKey()
{
	m_Key--;
}

int Player::getFruit()
{
	return m_fruit;
}

void Player::setFruit(int num)
{
	if (m_fruit >= 40)
	{
		setLife(1);
		m_fruit = 0;
	}
	m_fruit += num;
}

sf::Vector2f Player::getLlocation()
{
	return m_location;
}

void Player::setTimee(sf::Clock& timePassed)
{
	if (m_time - (timePassed.getElapsedTime().asSeconds()) <= 0)
	{
		setDisqualifications(-5);
		m_time = m_timeeee;
		timePassed.restart();
		m_location = m_startPosition;
		
	}

}
