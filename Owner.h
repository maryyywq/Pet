#pragma once
#include <string>
#include <vector>
#include "Pet.h"
#include <map>

class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;
    std::map<std::string, Pet*> pets; 
public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
    {
        setOwnerName(ownerName);
        setOwnerAge(ownerAge);
        setMoney(money);
    }

    //Запрет использования копирования
    Owner(const Owner&) = delete;
    void operator=(const Owner&) = delete;

    ~Owner() = default; 

    //Геттеры
    std::string getName() const { return this->ownerName; }
    int getAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }
    const std::map <std::string, Pet*>& getPets() const { return this->pets; }

    //Сеттеры
    void setOwnerName(const std::string& ownerName) {
        if (ownerName.empty()) {
            throw std::invalid_argument("Имя владельца не может быть пустым!");
        }
        this->ownerName = ownerName;
    }

    void setOwnerAge(int ownerAge) {
        if (ownerAge < 0) {
            throw std::invalid_argument("Возраст владельца не может быть отрицательным!");
        }
        this->ownerAge = ownerAge;
    }

    void setMoney(int money) {
        if (money < 0) {
            throw std::invalid_argument("Количество денег не может быть отрицательным!");
        }
        this->money = money;
    }

    void addNewPet(Pet* pet) { 
        pets[pet->name] = pet; 
    }

    void removePet(std::string name) {
        pets.erase(name);
    }

    Pet* getPet(std::string name) {
        auto pet = pets[name];
        if (pet == nullptr)
            std::cout << "Такого питомца у этого хозяина нет!" << std::endl;
        return pet;
    }

    Owner& operator+=(Pet* newpet) {
        addNewPet(newpet);
        return *this;
    }

    void walk(std::string name, Weather weather) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (weather == STORM || weather == RAINY || weather == WINDY) {
            mypet->status->setMood(AFRAID);
            mypet->status->setHealth(mypet->status->getHealth() - mypet->healthCost);
            if (mypet->status->getHealth() < 0) mypet->status->setHealth(0);
            std::cout << name << " испугался(ась) из-за плохой погоды." << std::endl;
        }
        else {
            mypet->status->setMood(HAPPY);
            std::cout << name << " гуляет и наслаждается хорошей погодой." << std::endl;
        }
        mypet->status->setEnergy(mypet->status->getEnergy() - mypet->walkEnergyCost);
        mypet->status->setSatiety(mypet->status->getSatiety() - mypet->satietyCost);
        if (mypet->status->getEnergy() < 0) mypet->status->setEnergy(0);
    }

    void play(std::string name, Game game) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (mypet->status->getEnergy() >= game.getEnergyCost()) {
            mypet->status->setMood(HAPPY);
            mypet->status->setEnergy(mypet->status->getEnergy() - game.getEnergyCost());
            mypet->status->setSatiety(mypet->status->getSatiety() - mypet->satietyCost);
            std::cout << name << " поиграл(а) и очень счастлив(а)!" << std::endl;
        }
        else {
            std::cout << name << " слишком устал(а) для игры." << std::endl;
        }
    }
}; 

std::ostream& operator<<(std::ostream& stream, const Owner& owner) {
    stream << "Имя владельца: " << owner.getName() << std::endl;
    stream << "Возраст: " << owner.getAge() << std::endl;
    stream << "Количество денег: " << owner.getMoney() << std::endl;
    stream << "Питомцы: " << std::endl;
    for (auto& pair : owner.getPets())
    {
        stream << "\t" << pair.first << std::endl;
    }
    return stream;
}