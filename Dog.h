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
};