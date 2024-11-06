#pragma once
#include <string>

class PetItem {
protected:
    std::string name;
    int value;
    int cost;

public:
    PetItem() : name(""), value(0), cost(0) {}
    PetItem(const std::string& n, int v, int c)
        : name(n), value(v), cost(c) {} // Исправлено: теперь передаются правильные параметры в конструктор

    // Конструктор копирования
    PetItem(const PetItem& other)
        : name(other.name), value(other.value), cost(other.cost) {}

    virtual ~PetItem() = default; // Деструктор по умолчанию

    // Геттеры
    std::string getName() const { return this->name; }
    int getValue() const { return this->value; }
    int getCost() const { return this->cost; }

    // Сеттеры
    void setName(const std::string& fn) { this->name = fn; }
    void setValue(int nv) { this->value = nv; }
    void setCost(int c) { this->cost = c; }

    virtual std::string getType() = 0; // Чисто виртуальная функция
};
