#pragma once
#include <string>
#include "Pet.h"

//Класс кошки
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age, Sex sex) : Pet(name, age, sex) {}
    ~Cat() = default; //Деструктор по умолчанию

    Cat operator + (const Cat& otherpet) const
    {
        if (sex != otherpet.getSex() && abs(age - otherpet.getAge()) <= 2) {
            srand(time(0));

            if (rand() % 100 <= 50) {
                std::string newname = "Маленький " + (sex == MALE ? name : otherpet.getName());
                std::cout << newname << " родился!" << std::endl;
                return Cat(newname, 0, MALE);
            }
            else {
                std::string newname = "Маленькая " + (sex == FEMALE ? name : otherpet.getName());
                std::cout << newname << " родилась!" << std::endl;
                return Cat(newname, 0, FEMALE);
            }
        }
        else {
            throw std::exception("Новый котенок не получится!");
        }
    }

    void makeSound() const override {
        std::cout << name << " говорит: Мяу!" << std::endl;
    }

    void setAge(int age) override {
        if (age < 0 || age > 26) {
            throw std::invalid_argument("Возраст кошки должен быть в пределах от 0 до 26.");
        }
        Pet::setAge(age);
    }

    std::string getType() const override { return "Cat"; }
};
