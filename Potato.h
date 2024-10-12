#pragma once
#include "Food.h"

class Potato : public Food
{
public:
	std::string getType() { return "Potato"; }
};