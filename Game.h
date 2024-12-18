#pragma once
#include <string>
#include <iostream>

// ����� ����
class Game {
protected:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    // ����������� �����������
    Game(const Game& other)
        : gameName(other.gameName), funValue(other.funValue), energyCost(other.energyCost) {
    }
    ~Game() = default; // ���������� �� ���������


    // �������
    std::string getGameName() const { return this->gameName; }
    int getFunValue() const { return this->funValue; }
    int getEnergyCost() const { return this->energyCost; }

    // �������
    void setGameName(const std::string& gn) { this->gameName = gn; }
    void setFunValue(int fv) { this->funValue = fv; }
    void setEnergyCost(int ec) { this->energyCost = ec; }

    void play() { std::cout << "� ����� � ����������� ����!" << std::endl; }
};
