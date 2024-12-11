#pragma once
#include <string>
#include "Pet.h"
#include "MeowBehavior.h"
#include "RunBehavior.h"

//Класс кошки
class Cat : public Pet {
public:
    Cat() : Pet() { setSoundBehavior(new MeowBehavior()), setMoveBehavior(new RunBehavior); }

    Cat(const std::string& name, int age, Sex sex) : Pet(name, age, sex, new MeowBehavior(), new RunBehavior()) {}

    ~Cat()
    {
        std::cout << "Ваш кот " << name << " убежал!" << std::endl;
    }

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


    void setAge(int age) override {
        if (age < 0 || age > 26) {
            throw std::invalid_argument("Возраст кошки должен быть в пределах от 0 до 26.");
        }
        Pet::setAge(age);
    }

    std::string getType() const override { return "Cat"; }
};
