#pragma once
#include <string>
#include "Object.h"

class PetItem :public Object {
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
        

    //����������� �����������
    PetItem(const PetItem& other)
        : name(other.name), value(other.value), cost(other.cost) {}

    virtual ~PetItem() = default; //���������� �� ���������

    //�������
    virtual std::string getName() const { return name; }
    virtual int getValue() const { return value; }
    virtual int getCost() const { return cost; }

    //�������
    virtual void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("�������� �������� �� ����� ���� ������!");
        }
        this->name = name;
    }

    virtual void setValue(int value) {
        if (value < 0) {
            throw std::invalid_argument("�������� �������� �� ����� ���� �������������!");
        }
        this->value = value;
    }

    virtual void setCost(int cost) {
        if (cost < 0) {
            throw std::invalid_argument("��������� �������� �� ����� ���� �������������!");
        }
        this->cost = cost;
    }
};
