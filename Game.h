#pragma once
#include <string>

//Класс игры
class Game {
private:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    ~Game() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getGameName() const { return gameName; }
    int getFunValue() const { return funValue; }
    int getEnergyCost() const { return energyCost; }

    //Сеттеры
    void setGameName(const std::string& gn) { gameName = gn; }
    void setFunValue(int fv) { funValue = fv; }
    void setEnergyCost(int ec) { energyCost = ec; }

    virtual void play() { std::cout << "я играю в стандартную игру!" << std::endl; }
};