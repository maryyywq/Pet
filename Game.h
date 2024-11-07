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
    void setGameName(const std::string& gameName) {
        if (gameName.empty()) {
            throw std::invalid_argument("Название игры не может быть пустым!");
        }
        this->gameName = gameName;
    }

    void setFunValue(int funValue) {
        if (funValue < 0) {
            throw std::invalid_argument("Значение веселья не может быть отрицательным!");
        }
        this->funValue = funValue;
    }

    void setEnergyCost(int energyCost) {
        if (energyCost < 0) {
            throw std::invalid_argument("Энергозатраты не могут быть отрицательными!");
        }
        this->energyCost = energyCost;
    }

    void play() { std::cout << "я играю в стандартную игру!" << std::endl; }
};
