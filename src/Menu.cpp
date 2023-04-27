#include "Menu.h"

Menu::Menu(sf::RenderWindow & window, bool& start) : m_window(window)
{
	/*Resources::getInstance().m_menu.play();
	Resources::getInstance().m_menu.setLoop(true);*/
	m_button.emplace_back(std::make_unique<ExplanationGame>(m_window));
	m_button.emplace_back(std::make_unique<NewGame>(m_window, start));
	m_button.emplace_back(std::make_unique<ExitGame>(m_window));
	m_bgmenu = sf::Sprite(Resources::getInstance().getImg("bb"));
	//// Resources::getInstance().getImg("bb");
	///*if (it == Resources::getInstance().m_images.end())
	//	exit(1);
	//auto& vec = it->second;/*
	//
}

Menu::~Menu()
{
//	Resources::getInstance().m_menu.stop();
}

void Menu::open()
{
	draw();
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				exit(1);
			case sf::Event::MouseButtonPressed:
				sf::Vector2f vec;
				vec = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				for (size_t i = 0; i < m_button.size(); i++)
				{
					if (m_button[i]->isInRect(vec)) {
						m_button[i]->execute();
						if (i == 1)
							return;
						break;

					}
				}
				break;
			}
		}
		m_window.clear();
		draw();
		m_window.display();
	}

}

void Menu::draw()
{
	m_window.draw(m_bgmenu);
	for (auto& i : m_button)
		i->draw(m_window);
}




