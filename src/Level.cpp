#include "Level.h"
#include "Board.h"
#include <exception>
#include "MyException.h"
Level::Level(const std::string fileName,Player& player) : m_board(fileName, m_monster, player),m_clock(), m_informationDisplay()
{
	Resources::getInstance().getMusic("BackgroundMusic")->play();//הפעלת מוסיקה
	Resources::getInstance().getMusic("BackgroundMusic")->setLoop(true);
}
Level::~Level()
{
	Resources::getInstance().getMusic("BackgroundMusic")->stop();//עצירת מוסיקה
}
//פונקציה שמנהלת שלב
bool Level::run(sf::RenderWindow& window, const int& numOfLevel,Player& player)
{
while (window.isOpen())//כל עוד החלון פתוח
	{
		window.clear();//מנקים
		
		m_board.draw(window, numOfLevel);// שליחה לפונקציה שמדפיסה את כל האוביקטים הסטטים והרקע
		//זימון לפונקציה שמטפלת בתצוגת מידה
		m_informationDisplay.displayData(window, player.getDisqualifications(), player.getFruit(), player.getLife(), player.getCoins(),numOfLevel,
			player.getTime() - m_timePassed.getElapsedTime().asSeconds());
			player.setTimee(m_timePassed);//סדיקה עם ניגמר הזמן
		draw(window, player);//הדפסה של השחקן והמפלצות
		window.display();
		player.setLastPosition();
		CheckLevelEvents(window,player);
		move(player);
		try{ mainCollision(player); //בידקה עם ש התנגשות
		}
		catch(MyException &e)
		{
			cout << e.what() << endl;
			if (e.getDoor())
				return true;
		}
		if (player.getLife()<=0)
			return false;
		
	}
return false;
}
//הדפסה של המפלצות והאוביקטים הסטטים
void Level::draw(sf::RenderWindow& window, Player& player)
{
	
	for (const auto& monster : m_monster)
		monster->draw(window);
	player.draw(window);
	/*updatBackgroundPosition();
	window.draw(m_background1);
	window.draw(m_background2);*/
}
//בדיקה עם יש לחיצה
void Level::CheckLevelEvents(sf::RenderWindow& window, Player& player)
{

	auto event = sf::Event{};
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
		{
			player.handleEvent(event.key.code);
			//player.move(getDeltaTime());
			move(player);
			break;
		}
		default:
			break;
		}
	//	player.shoot(getDeltaTime());
	}
}

//--------------------------------------------------------------------------------------------------------------
//טיפןל בתזוזה של השחקן המפלצות והיריות
void Level::move(Player& player)
{
	/*m_background1.move({ 100 * getDeltaTime().asSeconds(),0 });
	m_background2.move({ 100 * getDeltaTime().asSeconds(),0 });*/
	player.enter();
	player.move(m_clock.getElapsedTime());
	auto deltaTime = getDeltaTime();
	player.shoot(deltaTime);

	//.move(deltaTime);
	for (const auto& monster : m_monster)
	{
		monster.get()->setLastPosition();
		monster->move(deltaTime);
	}
}
//--------------------------------------------------------------------------------------------------------------
sf::Time Level::getDeltaTime()
{
	auto deltaTime = m_clock.restart();
	return deltaTime;
}
//קיראה לפונקציות של ההתנגשות
void Level::mainCollision(Player& player)
{
	playerCollideWithStaticObject( player);//התנגשות שחקן באוביקטים סטטים
    playerCollideWithMonster(player);//התנגשות שחקן במפלצת
	monsterCollideWithStaticObject();//התנגשות מפלצת באובביקטים סטטים
}

void Level::playerCollideWithStaticObject(Player& player)
{
	m_board.playerCollideWithStaticObjectt(player);
}

void Level::playerCollideWithMonster(Player& player)
{
	for (int i = 0; i < m_monster.size(); i++)//רצים על הווקטור של המפלצות
	{
		if (player.getGlobalBoundsOfSprite().intersects(m_monster[i]->getGlobalBoundsOfSprite()))//  בדיקה עם יש חפיפה בין שני האוביקטים
			processCollision(player, *m_monster[i]);// שליחה לפונקציה של טיפןל בהנגשות
	}
}
void Level::monsterCollideWithStaticObject()
{
  m_board.monsterCollideWithStaticObjectt(m_monster);
}


