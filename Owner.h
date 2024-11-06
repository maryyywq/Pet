#pragma once
#include <string>

class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}

    //Конструктор копирования
    Owner(const Owner& other)
        : ownerName(other.ownerName), ownerAge(other.ownerAge), money(other.money) {}

    ~Owner() = default; 

    //Геттеры
    std::string getOwnerName() const { return this->ownerName; }
    int getOwnerAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }

    //Сеттеры
    void setOwnerName(const std::string& ownerName) { this->ownerName = ownerName; }
    void setOwnerAge(int ownerAge) { this->ownerAge = ownerAge; }
    void setMoney(int money) { this->money = money; }
};