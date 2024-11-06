#pragma once
#include <string>
#include "PetItem.h"

// Класс еды
class Food : public PetItem {
public:
    Food() : PetItem() {}
    Food(const std::string& foodName, int nutritionValue, int cost)
        : PetItem(foodName, nutritionValue, cost) {}
    ~Food() = default; // Деструктор по умолчанию

    std::string getType() override { return this->getType(); }
};
