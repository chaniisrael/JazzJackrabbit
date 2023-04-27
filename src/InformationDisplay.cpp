#include "InformationDisplay.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------
InformationDisplay::InformationDisplay()
{
	for (int i = 0; i < TOTAL_LIFE; i++)
		m_lives.push_back(Resources::getInstance().getImg("life"));

	for (int i = 0; i < DISQUALIFICATIONS; i++)
		m_disqualifications.push_back(Resources::getInstance().getImg("psilot"));


	//m_life = sf::Text("Life: ", Resources::getInstance().m_font);
	m_score = sf::Text("Score: ", Resources::getInstance().m_font);

	m_level = sf::Text("Level: ", Resources::getInstance().m_font);

	m_fruit = sf::Text("fruit: ", Resources::getInstance().m_font);

	auto color = sf::Color::Green;

	setDtata(m_score, 30, {200,10 }, color);
	setDtata(m_level, 30, { 400, 10 }, color);
	setDtata(m_fruit, 30, { 600, 10 }, color);
}
//--------------------------------------------------------------------------------------------------------------
void InformationDisplay::displayData(sf::RenderWindow& window,  const int Disqualifications, const int fruit, const int life, const int score,  const int level, const int time)
{

	sf::Sprite sprite;
	sf::Vector2f startPosition = { 20,10 };
	sprite.setTexture(m_lives[0]);
	for (int i = 0; i < life; i++)
	{
		
		sprite.setPosition(startPosition);
		startPosition.x += (sprite.getGlobalBounds().width + 2);
		window.draw(sprite);
	} 

	sf::Sprite sprite1;
	sf::Vector2f startPosition2 = { 20,75 };
	sprite1.setTexture(m_disqualifications[0]);
	for (int i = 0; i < Disqualifications; i++)
	{

		sprite1.setPosition(startPosition2);
		startPosition2.x += (sprite1.getGlobalBounds().width + 2);
		window.draw(sprite1);
	}

	auto color = sf::Color::Green;
	window.draw(m_score); //הדפסה של הטקסט
	auto text1 = sf::Text(std::to_string(score), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text1, 30, {290,10 }, color);
	window.draw(text1);


	window.draw(m_level); //הדפסה של הטקסט
	auto text3 = sf::Text(std::to_string(level), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text3, 30, { 490,10 }, color);
	window.draw(text3);

	window.draw(m_fruit); //הדפסה של הטקסט
	auto text4 = sf::Text(std::to_string(fruit), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text4, 30, { 690,10 }, color);
	window.draw(text4);

	displayTime(window, time);
}
//--------------------------------------------------------------------------------------------------------------
void InformationDisplay::setDtata(sf::Text& text, int size, sf::Vector2f position, sf::Color color)
{
	text.setCharacterSize(size); //משנה גודל
	text.setPosition(position); //משנה מקום
	text.setColor(color); //משנה צבע
}
//--------------------------------------------------------------------------------------------------------------
//מסדרת את הזמן
void InformationDisplay::displayTime(sf::RenderWindow& window, const int time)
{
	auto text = sf::Text();
	auto color = sf::Color();
	if (time / 60 >= 10 && time % 60 >= 10)
		text = sf::Text(std::to_string(time / 60) + ":" + std::to_string(time % 60), Resources::getInstance().m_font);
	else if (time / 60 < 10 && time % 60 >= 10)
		text = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(time % 60), Resources::getInstance().m_font);
	else if (time / 60 >= 10 && time % 60 < 10)
		text = sf::Text(std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getInstance().m_font);
	else
		text = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getInstance().m_font);
	if (time % 60 <= 10 && time / 60 < 1)
		color = sf::Color::Red;
	else
		color = sf::Color::Green;
	setDtata(text, 30, { 800,10 }, color);
	window.draw(text);
}