#include "GameManager.h"
#include "Resources.h"
GameManager::GameManager() :m_player()
{
}
bool GameManager::run(sf::RenderWindow& window)
{

	bool  isSucsses = false;
	int numOfLevel = 0; //משתנה שמציין את מספר השלב
	auto levelFile = std::string("level0.txt");
	while (std::ifstream(levelFile))
	{
		try {
			Level level(levelFile, m_player);
			isSucsses = level.run(window, numOfLevel, m_player);//קריא לפונקציה שמנהלת שלב

			if (isSucsses == true)
			{
				numOfLevel++;
				isSucsses = false;
			}
			else
				return false;

			levelFile = std::string("level") + std::to_string(numOfLevel) + std::string(".txt");
		}
		catch (const Win & win)
		{
			return true;
		}

	}
	
	return true;
}

