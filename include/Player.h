#pragma once
#include "DinamicObject.h"
#include "ShootType.h"
#include <vector>
#include "const.h"
#include "State.h"
#include "StandingState.h"
//#include "Factory.h"
using std::vector;
class Player : public DinamicObject
{
public:
	Player();
	//Player() = default;
	~Player() = default;
	void setPlayer(const std::string& name, const sf::Vector2f& location, int width, int height, int time, int key, sf::Vector2f direction);
	virtual void handleInput(Input input);
	void handleEvent(sf::Keyboard::Key key);
	void enter();
	sf::Vector2f getPosition() const;
	virtual void move(sf::Time deltaTime)override;
	void shoot(sf::Time deltaTime);
	void drawShoot(sf::RenderWindow& window);
	int getLife();
	void setLife(int num);
	int getDisqualifications();
	void setDisqualifications(int num);
	int getCoins();
	void setCoins(int num);
	int getTime();
	void setTime(int num);
	int getKey();
	void setKey();
	int getFruit();
	void setFruit(int num);
	sf::Vector2f getLlocation();
	void setTimee(sf::Clock& timePassed);

protected:
	int m_life;
	int m_Disqualifications;
	int m_coins;
	int m_time;
	int m_timeeee;
	int m_Key;
	int m_fruit;
	sf::Vector2f m_door;
	sf::Vector2f m_location;
	//sf::Vector2f m_positionDestination;
	std::unique_ptr<State> m_state;
	vector<std::unique_ptr<ShootType>>m_shoot;
	//sf::Sprite m_sprite;
	
};
	