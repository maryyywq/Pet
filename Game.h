#pragma once
#include <string>
#include <iostream>

//����� ����
class Game {
protected:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    //����������� �����������
    Game(const Game& other)
        : gameName(other.gameName), funValue(other.funValue), energyCost(other.energyCost) {
    }
    ~Game() = default; //���������� �� ���������


    //�������
    std::string getGameName() const { return gameName; }
    int getFunValue() const { return funValue; }
    int getEnergyCost() const { return energyCost; }

    //�������
    void setGameName(const std::string& gameName) {
        if (gameName.empty()) {
            throw std::invalid_argument("�������� ���� �� ����� ���� ������!");
        }
        this->gameName = gameName;
    }

    void setFunValue(int funValue) {
        if (funValue < 0) {
            throw std::invalid_argument("�������� ������� �� ����� ���� �������������!");
        }
        this->funValue = funValue;
    }

    void setEnergyCost(int energyCost) {
        if (energyCost < 0) {
            throw std::invalid_argument("������������� �� ����� ���� ��������������!");
        }
        this->energyCost = energyCost;
    }

    void play() { std::cout << "� ����� � ����������� ����!" << std::endl; }
};
