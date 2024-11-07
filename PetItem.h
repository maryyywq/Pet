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
    PetItem(const std::string& name, int value, int cost) {
        setName(name);
        setValue(value);
        setCost(cost);
    }
        

    //Конструктор копирования
    PetItem(const PetItem& other)
        : name(other.name), value(other.value), cost(other.cost) {}

    virtual ~PetItem() = default; //Деструктор по умолчанию

    //Геттеры
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getCost() const { return cost; }

    //Сеттеры
    void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Название предмета не может быть пустым!");
        }
        this->name = name;
    }

    void setValue(int value) {
        if (value < 0) {
            throw std::invalid_argument("Значение предмета не может быть отрицательным!");
        }
        this->value = value;
    }

    void setCost(int cost) {
        if (cost < 0) {
            throw std::invalid_argument("Стоимость предмета не может быть отрицательной!");
        }
        this->cost = cost;
    }
};
