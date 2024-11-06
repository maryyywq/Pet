#pragma once
#include <string>

// Класс хозяина
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}

    // Конструктор копирования
    Owner(const Owner& other)
        : ownerName(other.ownerName), ownerAge(other.ownerAge), money(other.money) {}

    ~Owner() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getOwnerName() const { return this->ownerName; }
    int getOwnerAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }

    // Сеттеры
    void setOwnerName(const std::string& on) { this->ownerName = on; }
    void setOwnerAge(int oa) { this->ownerAge = oa; }
    void setMoney(int m) { this->money = m; }
};
