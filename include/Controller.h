#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "const.h"
#include "GameManager.h"
#include "Menu.h"
#include <iostream>
#include <chrono>
#include <thread>
class Controller
{
public:
	Controller();
	~Controller() = default;
	void run(); //������� ������ �� �����
protected:
	void gameResult(bool& isSucsses); //������� ������ ������ �����(������ �� ����) ����� �� ������ ������� ��������
	sf::RenderWindow m_window; //���� �����
	bool m_start;
	Menu m_menu;//�����

};




