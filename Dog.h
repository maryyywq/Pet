#pragma once
#include <string>
#include "Pet.h"

//����� ������
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age) : Pet(name, age) {}
    ~Dog() = default; //���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }

    void setAge(int age) override {
        if (age < 0 || age > 30) {
            throw std::invalid_argument("������� ������ ������ ���� � �������� �� 0 �� 30.");
        }
        Pet::setAge(age);
    }

    std::string getType() override { return "Dog"; }
};
