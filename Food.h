#pragma once
#include <string>
#include "PetItem.h"

// ����� ���
class Food : public PetItem {
public:
    Food() : PetItem() {}
    Food(const std::string& foodName, int nutritionValue, int cost)
        : PetItem(foodName, nutritionValue, cost) {}
    ~Food() = default; // ���������� �� ���������

    std::string getType() override { return this->getType(); }
};
