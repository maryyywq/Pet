#pragma once
#include <string>
#include "Pet.h"

//Класс собаки
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age, Sex sex) : Pet(name, age, sex) {}
    ~Dog() = default; //Деструктор по умолчанию

    Dog operator + (const Dog& otherpet) const 
    {
        if (sex != otherpet.getSex() && abs(age - otherpet.getAge()) <= 4) {
            srand(time(0));

            if (rand() % 100 <= 50) {
                std::string newname = "Маленький " + (sex == MALE ? name : otherpet.getName());
                std::cout << newname << " родился!" << std::endl;
                return Dog(newname, 0, MALE);
            }
            else {
                std::string newname = "Маленькая " + (sex == FEMALE ? name : otherpet.getName());
                std::cout << newname << " родилась!" << std::endl;
                return Dog(newname, 0, FEMALE);
            }
        }
        else {
            throw std::exception("Новая собачка не получится!");
        }
    }

    void makeSound() const override {
        std::cout << name << " говорит: Гав!" << std::endl;
    }

    void setAge(int age) override{
        if (age < 0 || age > 30) {
            throw std::invalid_argument("Возраст собаки должен быть в пределах от 0 до 30.");
        }
        Pet::setAge(age);
    }

    std::string getType() const override { return "Dog"; }
};
