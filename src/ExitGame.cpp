#include "ExitGame.h"

ExitGame::ExitGame(sf::RenderWindow& window) : Button(window, "exit", { 280,450 })
{
}

void ExitGame::execute()
{
	m_window.close();

}
