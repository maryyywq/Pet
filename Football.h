#pragma once
#include "Game.h"
#include <iostream>

class Football :
    public Game
{
private:
    int ballQuality;
public:
    Football() : Game() {
        ballQuality = 100;
    }

    Football(const Game& other) : Game(other) { 
        ballQuality = 100;
    }

    void play() { std::cout << "я пинаю м€ч!" << std::endl; }
};

