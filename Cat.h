#pragma once
#include <string>
#include "Pet.h"
#include "MeowBehavior.h"
#include "RunBehavior.h"

//����� �����
class Cat : public Pet {
public:
    Cat() : Pet() { setSoundBehavior(new MeowBehavior()), setMoveBehavior(new RunBehavior); }

    Cat(const std::string& name, int age, Sex sex) : Pet(name, age, sex, new MeowBehavior(), new RunBehavior()) {}

    ~Cat()
    {
        std::cout << "��� ��� " << name << " ������!" << std::endl;
    }

    Cat operator + (const Cat& otherpet) const
    {
        if (sex != otherpet.getSex() && abs(age - otherpet.getAge()) <= 2) {
            srand(time(0));

            if (rand() % 100 <= 50) {
                std::string newname = "��������� " + (sex == MALE ? name : otherpet.getName());
                std::cout << newname << " �������!" << std::endl;
                return Cat(newname, 0, MALE);
            }
            else {
                std::string newname = "��������� " + (sex == FEMALE ? name : otherpet.getName());
                std::cout << newname << " ��������!" << std::endl;
                return Cat(newname, 0, FEMALE);
            }
        }
        else {
            throw std::exception("����� ������� �� ���������!");
        }
    }


    void setAge(int age) override {
        if (age < 0 || age > 26) {
            throw std::invalid_argument("������� ����� ������ ���� � �������� �� 0 �� 26.");
        }
        Pet::setAge(age);
    }

    std::string getType() const override { return "Cat"; }
};
