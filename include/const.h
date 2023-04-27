#pragma once

const auto MONSTER = '!';
const auto MONSTER2 = '<';
const auto WALL = '#';
const auto SPACE = ' ';
const auto PLAYER = '/';
const auto DISQUALIFICATIONS_GIFT = '%';
const auto COINS = '$';
const auto SOIL = '@';
const auto DOOR = '+';
const auto KEY = '-';
const auto DOKAR = '*';
const auto BANANA = '?';
const auto PINEAPPLE = '>';
const auto GIFT = '&';
const auto TOTAL_LIFE = 3;
const auto LIFE = 2;
const auto DISQUALIFICATIONS = 5;
const auto WIDTH_OF_BOARD = 680;
const auto HIGHT_OF_WINDOW = 1200;
const auto EPSILON = 1;
const auto SPEEDSHOOT = 20;





enum Input
{
	PRESS_LEAFT,
	PRESS_RIGHT,
	PRESS_UP,
	PRESS_DOWN,
	PRESS_STOP,
	PRESS_FALL
};


enum Directions
{
	left,
	right,
	up,
	down,
	Default
};


