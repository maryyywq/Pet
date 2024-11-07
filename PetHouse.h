#pragma once
#include <string>
#include <iostream>

class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

    //Статическое поле для отслеживания количества домов
    static int houseCount;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {
        //Увеличиваем счетчик при создании нового дома
        houseCount++;
    }

    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {
        houseCount++;
    }

    //Конструктор копирования
    PetHouse(const PetHouse& other)
        : houseName(other.houseName), address(other.address), comfortLevel(other.comfortLevel) {
        houseCount++;
    }

    ~PetHouse() {
        //Уменьшаем счетчик при удалении дома
        houseCount--;
    }

    //Геттеры
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    //Сеттеры
    void setHouseName(const std::string& houseName) {
        if (houseName.empty()) {
            throw std::invalid_argument("Название дома не может быть пустым!");
        }
        this->houseName = houseName;
    }

    void setAddress(const std::string& address) {
        if (address.empty()) {
            throw std::invalid_argument("Адрес не может быть пустым!");
        }
        this->address = address;
    }

    void setComfortLevel(int comfortLevel) {
        if (comfortLevel < 0 || comfortLevel > maxComfort) {
            throw std::invalid_argument("Уровень комфорта должен быть в диапазоне от 0 до " + std::to_string(maxComfort) + "!");
        }
        this->comfortLevel = comfortLevel;
    }

    //Статический метод для получения количества домов
    static int getHouseCount() {
        return houseCount;
    }

    static const int maxComfort = 100;
};

//Инициализация статического поля
int PetHouse::houseCount = 0;