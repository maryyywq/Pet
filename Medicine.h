#pragma once
#include <string>
#include "PetItem.h"

//����� ���������
class Medicine : public PetItem {
public:
    Medicine() : PetItem() {}
    Medicine(const std::string& name, int value, int cost)
        : PetItem(name, value, cost) {}
    ~Medicine() = default; //���������� �� ���������

    std::string getType() override { return "Medicine"; }
};