#pragma once
#include <string>

class PetItem {
protected:
    std::string name;
    int value;
    int cost;

public:
    PetItem() : name(""), value(0), cost(0) {}
    PetItem(const std::string& name, int value, int cost)
        : name(name), value(value), cost(cost) {} 

    //����������� �����������
    PetItem(const PetItem& other)
        : name(other.name), value(other.value), cost(other.cost) {}

    virtual ~PetItem() = default; //���������� �� ���������

    //�������
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getCost() const { return cost; }

    //�������
    void setName(const std::string& name) { this->name = name; }
    void setValue(int value) { this->value = value; }
    void setCost(int cost) { this->cost = cost; }

    virtual std::string getType() = 0; //����� ����������� �������
};
