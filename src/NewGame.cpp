#include "NewGame.h"

NewGame::NewGame(sf::RenderWindow& window, bool& start) : Button(window, "play", { 500,450 }), m_start(start)
{

}
void NewGame::execute()
{
	m_start = true;
}