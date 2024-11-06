#pragma once
#include <string>
#include "Pet.h"

// ласс кошки
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age) : Pet(name, age) {}
    ~Cat() = default; //ƒеструктор по умолчанию

    void makeSound() const override {
        std::cout << name << " говорит: ћ€у!" << std::endl;
    }

    void setAge(int age) override {
        if (age < 0 || age > 26) {
            throw std::invalid_argument("¬озраст кошки должен быть в пределах от 0 до 26.");
        }
        Pet::setAge(age);
    }

    std::string getType() override { return "Cat"; }
};
