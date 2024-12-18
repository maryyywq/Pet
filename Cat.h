#pragma once
#include <string>
#include "Pet.h"

//����� �����
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age) : Pet(name, age) {}
    ~Cat() = default; //���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }

    void setAge(int age) override {
        if (age < 0 || age > 26) {
            throw std::invalid_argument("������� ����� ������ ���� � �������� �� 0 �� 26.");
        }
        Pet::setAge(age);
    }

    std::string getType() override { return "Cat"; }
};
