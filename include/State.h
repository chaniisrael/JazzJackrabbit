#pragma once
using namespace std;
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <memory>
#include"Const.h"
class Player;

class State {
public:
	virtual ~State() { }

	virtual unique_ptr<State>	handleInput(Input input) = 0;
	virtual void enter(Player& play) = 0;
	// ...

};