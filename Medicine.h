#pragma once
#include <string>
#include "PetItem.h"

// Класс лекарства
class Medicine : public PetItem {
public:
    Medicine() : PetItem() {}
    Medicine(const std::string& name, int value, int cost)
        : PetItem(name, value, cost) {}
    ~Medicine() = default; // Деструктор по умолчанию

    std::string getType() override { return this->getType(); }
};
