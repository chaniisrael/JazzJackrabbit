#include "ExplanationGame.h"

ExplanationGame::ExplanationGame(sf::RenderWindow& window) : Button(window, "Help", { 70,450 }) //, m_start(start)
{
}
void ExplanationGame::execute()
{
	sf::RenderWindow helpWindow(sf::VideoMode(HIGHT_OF_WINDOW,WIDTH_OF_BOARD), "Help"); //פתיחת חלון להסבר המשחק
	sf::Sprite sprite;
	sprite.setTexture(Resources::getInstance().getImg("help11"));

	while (helpWindow.isOpen()) //כל עוד החלון פתוח נכנס ללולאה
	{
		helpWindow.clear();
		helpWindow.draw(sprite);
		helpWindow.display();
		if (auto event = sf::Event{}; helpWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				helpWindow.close();
				break;
			}
			default:
				break;
			}
		}
	}
	//m_start=false;


}
