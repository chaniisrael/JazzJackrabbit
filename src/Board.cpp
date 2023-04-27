#include "Board.h"
#include <iostream>
#include "Level.h"


Board::Board(const std::string fileName, vector<std::unique_ptr<MonsterType>>& monster, Player& player) : m_file(std::ifstream(fileName))
{
	openBoardFile();//בידקה עם הקובץ נפתח
   run(player, monster);//הפונקציה האחרית על קריאה מקובץ
}
//מציג את הרקע ואת האוביקטים הסטטים
void Board::draw(sf::RenderWindow& window,int numOfLevel)
{
	if (numOfLevel > LIFE)
		throw Win();
	std::string levelFile = std::string("background") + std::to_string(numOfLevel);
	sf::Sprite sprite(Resources::getInstance().getImg(levelFile));
	window.draw(sprite);
	for (const auto& obj : m_gameBoard)
		obj->draw(window);
}
//פונקציה האחרית על קריאה מקובץ
void Board::run(Player& player, vector<std::unique_ptr<MonsterType>>& monster)
{
	int seconds,key;//משתנים שמציינים כמה הזמן יש במשחק וכמה מפתחות
	char character;//מחזיק תו
	float x, y;//מחזיק מיקום 
	m_file >> seconds>>key;
		std::string str;
		while (!m_file.eof())//כל עוד הקובץ לא הסתייים
		{
			while (std::getline(m_file, str))//מעתיק שורה מהקובץ לתוך משתנה
			{
				std::istringstream ss(str);
				ss >> x >> y >>character ;
				sf::Vector2f{ x,y };
				setObject(player,character, sf::Vector2f{ x,y}, monster, seconds,key);
			}	
		}
	}
//--------------------------------------------------------
//בדיקה עם הקובץ נפתח
void Board::openBoardFile()
{
	if (!m_file.is_open())
		//int i;
	throw exception("Can't open the file \n");
}
//הפונקתיה מקבלת תו ומכניסה לווקטור 
void Board::setObject(Player& player,char character, sf::Vector2f location, vector<std::unique_ptr<MonsterType>>& monster,int seconds,int key)
{
	switch (character)
	{
		
	case PLAYER:
		player.setPlayer("player",location, 90, 60, seconds, key, sf::Vector2f(0, 0));
		break;
	case MONSTER:
		monster.emplace_back(Factory::createMonster("monsterS", location, 80, 80, player));
		break;
	case MONSTER2:
		monster.emplace_back(Factory::createMonster("monsterR", location, 70, 70, player));
		break;
	case WALL:
		m_gameBoard.emplace_back(Factory::create("wall", location,90,220));
		break;
	case COINS:
		m_gameBoard.emplace_back(Factory::create("coin", location,40,40));
		break;
	case SOIL:
		m_gameBoard.emplace_back(Factory::create("soil", location,100,120));
		break;
	case DOOR:
		m_gameBoard.emplace_back(Factory::create("door", location, 150, 80));
		break;
	case KEY:
		m_gameBoard.emplace_back(Factory::create("key", location, 50, 50));
		break;
	case DOKAR:
		m_gameBoard.emplace_back(Factory::create("dokar", location, 75, 45));
		break;
	case GIFT:
		m_gameBoard.emplace_back(Factory::createGift(location, 50, 50));
		break;
	case BANANA:
		m_gameBoard.emplace_back(Factory::create("banana", location, 40, 40)); 
		break;
	case PINEAPPLE:
		m_gameBoard.emplace_back(Factory::create("pineapple", location, 70, 70));
			break;

      throw exception("Can't find the character \n");

	}
}
//התנגשות בין שחקן לאובייקטים סטטים
void Board::playerCollideWithStaticObjectt(Player& player)
{
	bool flag = false;
	for (int i = 0; i < m_gameBoard.size(); i++)//ריצה על הווקטור של האוביקטים הסטטים
	{
		if (player.getGlobalBoundsOfSprite().intersects(m_gameBoard[i]->getGlobalBoundsOfSprite()))//סדיקה אם קיים חפיפה בין שתי האוביקטיים
		{
			flag = true;
			processCollision(player, *m_gameBoard[i]);//שליחה לפונקציה שמטפלת בהתנגשות
			//בודק אם התו שונה קיר אבן ודלת מוחק
			if(typeid(*m_gameBoard[i]).name() != typeid(Wall).name() && typeid(*m_gameBoard[i]).name() != typeid(soil).name() && typeid(*m_gameBoard[i]).name() != typeid(Dokar).name()&& typeid(*m_gameBoard[i]).name() != typeid(Door).name())
			m_gameBoard.erase(m_gameBoard.begin() + i);//מחיקה
		}
	}
	if (!flag)
		player.handleInput(PRESS_DOWN);
}
//התנגשות בין מפלצת לאוביקטים סטטים
void Board::monsterCollideWithStaticObjectt(vector<std::unique_ptr<MonsterType>>& monster)
{
	for (int i = 0; i < monster.size(); i++)//ריצה על הווקטור של האוביקטים מפלצות
	{
		for (int j = 0; j < m_gameBoard.size(); j++)//ריצה על הווקטור של האוביקטים הסטטים
		{
			if (monster[i]->getGlobalBoundsOfSprite().intersects(m_gameBoard[j]->getGlobalBoundsOfSprite()))//בדיקה אם קיים חפיפה בין שתי האוביקטיים
			{
				//אם התו שווה לקיר או אבן
				if (typeid(*m_gameBoard[j]).name() == typeid(Wall).name() || typeid(*m_gameBoard[j]).name() == typeid(soil).name())
				processCollision(*monster[i], *m_gameBoard[j]);//טיפול בהתנגשות
				if(monster[i]->getLifeS()<=0)
					m_gameBoard.erase(m_gameBoard.begin() + i);
			}
		}
	}
}








