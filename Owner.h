#pragma once
#include <string>
#include <vector>
#include "Pet.h"

class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;
    std::vector<std::shared_ptr<Pet>> pets;
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
    const std::vector<std::shared_ptr<Pet>>& getPets() const { return this->pets; }

    //Сеттеры
    void setOwnerName(const std::string& ownerName) { this->ownerName = ownerName; }
    void setOwnerAge(int ownerAge) { this->ownerAge = ownerAge; }
    void setMoney(int money) { this->money = money; }

    void addNewPet(std::shared_ptr<Pet> pet) { pets.push_back(pet); }
    void removePet(std::shared_ptr<Pet> pet) {
        int index = -1;
        for (int i = 0; i < pets.size(); i++)
        {
            if (pets[i] == pet) {
                index = i;
                break;
            }
        }
        if (index != -1) pets.erase(pets.cbegin() + index);
        else std::cout << "Такого питомца у этого хозяина нет!" << std::endl;
    }
    std::shared_ptr<Pet> getPet(std::string name) {
        for (int i = 0; i < pets.size(); i++)
        {
            if (pets[i]->getName() == name) {
                return pets[i];
            }
        }
        std::cout << "Такого питомца у этого хозяина нет!" << std::endl;
        return nullptr;
    }
}; 