#pragma once

#include "GameObject.h"

#include <iostream>
#include <typeinfo>
#include "DinamicObject.h"


// Sample struct for exception throwing
struct UnknownCollision : public std::runtime_error
{
	UnknownCollision(GameObject& a, GameObject& b)
		: std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
	{
	}
};

void processCollision(GameObject& object1, GameObject& object2);
