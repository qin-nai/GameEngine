#include <iostream>
#include "Director.h"
using namespace dhgame;

static Director* instance = nullptr;

Director::Director() {

}
Director::~Director() {

}

Director* Director::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Director();
	}
	return instance;
}
