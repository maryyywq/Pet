#pragma once
#include <string>
#include "Pet.h"
#include "BarkBehavior.h"
#include "RunBehavior.h"

//����� ������
class Dog : public Pet {
public:
    Dog() : Pet() { setSoundBehavior(new BarkBehavior()), setMoveBehavior(new RunBehavior); }

    Dog(const std::string& name, int age, Sex sex) : Pet(name, age, sex, new BarkBehavior(), new RunBehavior()) {}
    ~Dog() = default; //���������� �� ���������

    Dog operator + (const Dog& otherpet) const 
    {
        if (sex != otherpet.getSex() && abs(age - otherpet.getAge()) <= 4) {
            srand(time(0));

            if (rand() % 100 <= 50) {
                std::string newname = "��������� " + (sex == MALE ? name : otherpet.getName());
                std::cout << newname << " �������!" << std::endl;
                return Dog(newname, 0, MALE);
            }
            else {
                std::string newname = "��������� " + (sex == FEMALE ? name : otherpet.getName());
                std::cout << newname << " ��������!" << std::endl;
                return Dog(newname, 0, FEMALE);
            }
        }
        else {
            throw std::exception("����� ������� �� ���������!");
        }
    }

    void setAge(int age) override{
        if (age < 0 || age > 30) {
            throw std::invalid_argument("������� ������ ������ ���� � �������� �� 0 �� 30.");
        }
        Pet::setAge(age);
    }

    std::string getType() const override { return "Dog"; }
};
