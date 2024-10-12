#pragma once
#include "Game.h"
#include <iostream>

class Football :
    public Game
{
public:
    void play() { std::cout << "€ пинаю м€ч!" << std::endl; }
};

