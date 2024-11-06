#pragma once
#include <string>
#include <iostream>

//Класс игры
class Game {
protected:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    //Конструктор копирования
    Game(const Game& other)
        : gameName(other.gameName), funValue(other.funValue), energyCost(other.energyCost) {
    }
    ~Game() = default; //Деструктор по умолчанию


    //Геттеры
    std::string getGameName() const { return gameName; }
    int getFunValue() const { return funValue; }
    int getEnergyCost() const { return energyCost; }

    //Сеттеры
    void setGameName(const std::string& gameName) { this->gameName = gameName; }
    void setFunValue(int funValue) { this->funValue = funValue; }
    void setEnergyCost(int energyCost) { this->energyCost = energyCost; }

    void play() { std::cout << "я играю в стандартную игру!" << std::endl; }
};
