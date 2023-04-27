#pragma once
#include <map>
//#include "GameObject.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "StaticObject.h"
#include <iostream>
#include <memory>
#include <string>
#include "MonsterType.h"
#include "GiftType.h"
#include "ShootType.h"
#include <SFML/Graphics.hpp>

//#include "Player.h"


typedef std::map<std::string, std::unique_ptr<StaticObjet>(*)( const sf::Vector2f & location, float height, const float width)> mymap;
typedef std::map<std::string, std::unique_ptr<MonsterType>(*)( const sf::Vector2f & location, float height,  float width, Player & player)> monstr;
//typedef std::vector<std::unique_ptr<MonsterType>(*)(sf::Vector2f, float height, float width)> monstr;
typedef std::vector<std::unique_ptr<GiftType>(*)( const sf::Vector2f & location,  float height, float width)> gift;
typedef std::map<std::string, std::unique_ptr<ShootType>(*)( const sf::Vector2f & location, float height, const float width)> mapshoot;


class Factory
{
public:
	Factory() = default;
	~Factory() = default;
	static std::unique_ptr<StaticObjet> create(const std::string& name, const sf::Vector2f& location, float height, const float width);
	static bool registerit(const std::string& name, std::unique_ptr<StaticObjet>(*f)(const sf::Vector2f& location, float height, const float width));

	static std::unique_ptr<MonsterType> createMonster(const std::string& name, const sf::Vector2f& location, float height, float width, Player& player);
	static bool registeritMonster(const std::string& name,std::unique_ptr<MonsterType>(*f)(const sf::Vector2f& location, float height, float width, Player& player));

	static std::unique_ptr<GiftType> createGift(const sf::Vector2f& location, float height, float width);
	static bool registeritGift(std::unique_ptr<GiftType>(*f)(const sf::Vector2f& location, float height, float width));

	static std::unique_ptr<ShootType> createShoot(const std::string& name, const sf::Vector2f& location, float height, const float width);
	static bool registeritShoot(const std::string& name, std::unique_ptr<ShootType>(*f)(const sf::Vector2f& location, float height, const float width));



private:
	static mymap& getMap();
	
	static monstr& getMapMonster();

    static gift& getVecGift();

	static mapshoot& getMapcShoot();
	
};

