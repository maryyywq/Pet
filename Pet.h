#pragma once
#include <iostream>
#include <string>
#include "Status.h"
#include "PetHouse.h"
#include "GameDay.h"
#include "Game.h"
#include "Medicine.h"
#include "Food.h"
#include "PetItem.h"
#include "Mood.h"
#include "Sex.h"

//Абстрактный класс питомца
class Pet : public Object {
    friend class Owner;
protected:
    std::string name;
    int age;
    Status status;
    Sex sex;

public:
    Pet() : name(""), age(0), status(), sex(MALE) {}
    Pet(const std::string& name, int age, Sex sex) {
        setName(name);
        setAge(age);
        setSex(sex);
    }

    //Конструктор копирования
    Pet(const Pet& other)
        : name(other.name), age(other.age), status(other.status), sex(other.sex) {
    }

    virtual ~Pet() = default; //Виртуальный деструктор по умолчанию

    //Геттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }
    const Status& getStatus() const { return status; }
    Sex getSex() const { return sex; }

    //Сеттеры
    void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Имя питомца не может быть пустым.");
        }
        this->name = name;
    }

    virtual void setAge(int age) {
        this->age = age;
    }

    void setStatus(const Status& status) {
        this->status = status;
    }

    void setSex(Sex sex) {
        this->sex = sex;
    }


    virtual void makeSound() const = 0; //Чисто виртуальная функция

    void use(PetItem* item) {
        if (item->getType() == "Food") {
            int newSatiety = status.getSatiety() + item->getValue();
            status.setSatiety(newSatiety);
            if (status.getSatiety() == Status::maxSatiety) {
                status.setMood(HAPPY);
            }
            std::cout << name << " покушал(а) " << item->getName() << " и его(ее) голод уменьшился." << std::endl;
            makeSound(); //Питомец издает звук после еды
        }
        else if (item->getType() == "Medicine") {
            status.setHealth(status.getHealth() + item->getValue());
            if (status.getHealth() > Status::maxHealth) {
                status.setHealth(Status::maxHealth);
                status.setMood(HAPPY);
            }
            std::cout << name << " принял(а) " << item->getName() << " и его(ее) здоровье улучшилось." << std::endl;
        }
    }

    void sleep(PetHouse house) {
        status.setEnergy(status.getEnergy() + house.getComfortLevel());
        status.setSatiety(status.getSatiety() - sleepHungerCost);
        if (status.getEnergy() > Status::maxEnergy) {
            status.setEnergy(Status::maxEnergy);
        }

        if (status.getEnergy() >= 50) {
            std::cout << name << " хорошо отдохнул(а)!" << std::endl;
            status.setMood(HAPPY);
        }
        else {
            std::cout << name << " не очень хорошо отдохнул(а) :(" << std::endl;
            status.setMood(SAD);
        }
        makeSound(); //Питомец издает звук после сна
    }

    friend bool areFriends(Pet* Pet1, Pet* Pet2);

    static const int walkEnergyCost = 5;
    static const int healthCost = 5;
    static const int satietyCost = 10;
    static const int sleepHungerCost = 40;
};

std::ostream& operator<<(std::ostream& stream, const Pet& pet) {
    stream << "Имя питомца: " << pet.getName() << std::endl;
    stream << "Возраст питомца: " << pet.getAge() << std::endl;
    stream << "Сытость: " << pet.getStatus().getSatiety() << std::endl;
    stream << "Энергия: " << pet.getStatus().getEnergy() << std::endl;
    stream << "Здоровье: " << pet.getStatus().getHealth() << std::endl;
    stream << "Настроение: " << getMoodString(pet.getStatus().getMood()) << std::endl;
    return stream;
}

bool areFriends(Pet* Pet1, Pet* Pet2)
{
    if (Pet1->getType() == Pet2->getType() && abs(Pet1->age - Pet2->age) <= 2)
    {
        Pet1->status.setMood(HAPPY);
        Pet2->status.setMood(HAPPY);
        std::cout << Pet1->name << " и " << Pet2->name << " - друзья!" << std::endl;
        return true;
    }
    else
    {
        Pet1->status.setMood(ANGRY);
        Pet2->status.setMood(ANGRY);
        std::cout << Pet1->name << " и " << Pet2->name << " совсем не друзья!" << std::endl;
        return false;
    }
}