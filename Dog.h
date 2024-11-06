#pragma once
#include <string>
#include "Pet.h"

//Класс собаки
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age) : Pet(name, age) {}
    ~Dog() = default; //Деструктор по умолчанию

    void makeSound() const override {
        std::cout << name << " говорит: Гав!" << std::endl;
    }

    void setAge(int age) override {
        if (age < 0 || age > 30) {
            throw std::invalid_argument("Возраст собаки должен быть в пределах от 0 до 30.");
        }
        Pet::setAge(age);
    }

    std::string getType() override { return "Dog"; }
};
