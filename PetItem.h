#pragma once
#include <string>
#include "Object.h"

class PetItem :public Object{
protected:
    std::string name;
    int value;
    int cost;

public:
    PetItem() : name(""), value(0), cost(0) {}
    PetItem(const std::string& name, int value, int cost)
        : name(name), value(value), cost(cost) {} 

    //Конструктор копирования
    PetItem(const PetItem& other)
        : name(other.name), value(other.value), cost(other.cost) {}

    virtual ~PetItem() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getCost() const { return cost; }

    //Сеттеры
    void setName(const std::string& name) { this->name = name; }
    void setValue(int value) { this->value = value; }
    void setCost(int cost) { this->cost = cost; }
};
