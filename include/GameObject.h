#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <memory>
class GameObject
{
public:
	GameObject(const std::string& name, const sf::Vector2f& location,  float height,  float width);
	GameObject() = default;
	virtual~GameObject() = default;
	void draw(sf::RenderWindow& window);
	 void setObjet(const std::string& name, const sf::Vector2f& location,  float height,  float width);
	 sf::FloatRect getGlobalBoundsOfSprite();
	
protected:
	sf::Sprite m_sprite;
};
//Board::Board(Mario& mario, vector<std::unique_ptr<Enemy>>& enemies, int numLevel)
//{
//
//	auto it = Resources::getInstance().m_textures.find("background level 1");
//	if (it == Resources::getInstance().m_textures.end())
//		return;
//	auto& vec = it->second;
//	m_background.setTexture(vec[0]);
//	auto txt = m_background.getTexture();
//	auto texSize = txt->getSize();
//	auto newTexSize = sf::Vector2f(WIDTH_OF_WINDOW * 3, HEIGHT_OF_WINDOW);
//	auto scaleX = newTexSize.x * 1.00f / texSize.x;
//	auto scaleY = newTexSize.y * 1.00f / texSize.y;
//	m_background.setScale(scaleX, scaleY);
//	init(mario, enemies, numLevel);
//
//
//
//
//}
////-------------------------------------------------------------------------------------------------------------
//void Board::draw(sf::RenderWindow& window)const
//{
//	window.draw(m_background);
//	for (const auto& obj : m_objects)
//		obj->draw(window);
//}
//
////------------------------------------------------------------------------------------------------------------------------
//void Board::init(Mario& mario, vector<std::unique_ptr<Enemy>>& enemies, int numLevel)
//{
//
//	std::ifstream in;
//	char character;
//	in.open("level1.txt");
//	if (!in)
//		throw std::runtime_error("couldn't open the file");
//	//in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//
//	int seconds, difficulty = 1;
//	in >> seconds;
//
//	std::string str;
//	std::getline(in, str);
//
//	while (std::getline(in, str))
//	{
//		std::istringstream ss(str);
//		ss.exceptions(std::ifstream::failbit | std::ifstream::badbit);
//		float x, y;
//		char character;
//		ss >> x >> y >> character;
//		setObject(mario, enemies, sf::Vector2f{ x,y }, character, difficulty, seconds);
//	}
//
//}
////-----------------------------------------------------------------------------------------------------------------------------------------
//void Board::setObject(Mario& mario, vector<std::unique_ptr<Enemy>>& enemies, sf::Vector2f location, char character, int difficulty, int seconds)
//{
//	switch (character)
//	{
//	case MARIO:
//		mario.setData(location, 50, 50, seconds);
//		break;
//	case ENEMY:
//		enemies.emplace_back(Factory::createEnemy(location, 80, 80, difficulty));
//		break;
//	case PRESENT:
//		m_objects.emplace_back(Factory::createPresent(location, 50, 50));
//		break;
//	case COIN:
//		m_objects.emplace_back(Factory::createObject("coin", location, 50, 50));
//		break;
//	case STONE:
//		m_objects.emplace_back(Factory::createObject("stone", location, 50, 50));
//		break;
//	case WALL:
//		m_objects.emplace_back(Factory::createObject("wall", location, 50, 50));
//
//	}
