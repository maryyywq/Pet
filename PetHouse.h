#pragma once
#include <string>

// Класс дома питомца
class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {}
    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {}

    // Конструктор копирования
    PetHouse(const PetHouse& other)
        : houseName(other.houseName), address(other.address), comfortLevel(other.comfortLevel) {}

    ~PetHouse() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getHouseName() const { return this->houseName; }
    std::string getAddress() const { return this->address; }
    int getComfortLevel() const { return this->comfortLevel; }

    // Сеттеры
    void setHouseName(const std::string& hn) { this->houseName = hn; }
    void setAddress(const std::string& a) { this->address = a; }
    void setComfortLevel(int cl) {
        this->comfortLevel = (cl > this->maxComfort) ? this->maxComfort : cl;
    }

    static const int maxComfort = 100;
};
