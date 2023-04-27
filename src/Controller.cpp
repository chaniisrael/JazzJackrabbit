#include "Controller.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Controller::Controller() : m_window(sf::VideoMode(HIGHT_OF_WINDOW, WIDTH_OF_BOARD), "jazz rabbit"), m_start(false), m_menu(m_window, m_start)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמנהלת את המשחק
void Controller::run()
{
	bool isSucsses = true;
	m_menu.open();

	if (m_start)
	{
		GameManager game;
		isSucsses=game.run(m_window);//קריאה לפונקציה שמנהלת את המשחק
		gameResult(isSucsses);//קריאה פונקציה שבהתאם לתוצאת המשחק ניצחון או הפסד  מציגה את התמונה והסאונד המתאימים
	}
}

//--------------------------------------------------------------------------------------------------------------
//פונקציה שבהתאם לתוצאת המשחק(ניצחון או הפסד) מציגה את התמונה והסאונד המתאימים
void Controller::gameResult(bool& isSucsses)
{
 auto sprite = sf::Sprite();
 if (!isSucsses)
 {
 m_window.clear();
 sprite = sf::Sprite(Resources::getInstance().getImg("gameOver"));
 Resources::getInstance().getMusic("GameOverMusic")->play();

 }
 else
 {
 m_window.clear();
 sprite = sf::Sprite (Resources::getInstance().getImg("GameWin"));
 Resources::getInstance().getMusic("GameWin")->play();
 }
 m_window.draw(sprite);
 m_window.display();
 using namespace std::chrono_literals;
 std::this_thread::sleep_for(5s);
 
 if (!isSucsses)
	 Resources::getInstance().getMusic("GameOverMusic")->stop();
 else
	 Resources::getInstance().getMusic("GameWin")->stop();
 run();
 return;
 }


