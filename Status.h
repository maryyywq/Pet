#pragma once
#include "Mood.h"

//Класс состояния питомца
class Status {
private:
    int satiety;
    int energy;
    int health;
    Mood mood;

public:
    Status() {
        setSatiety(maxSatiety);
        setEnergy(maxEnergy / 2);
        setHealth(maxHealth);
        setMood(HAPPY);
    }


    //Конструктор копирования
    Status(const Status& other)
        : satiety(other.satiety), energy(other.energy), health(other.health), mood(other.mood) {}

    ~Status() = default; //Деструктор по умолчанию

    //Геттеры
    int getSatiety() const { return satiety; }
    int getEnergy() const { return energy; }
    int getHealth() const { return health; }
    Mood getMood() const { return mood; }

    //Сеттеры
    void setSatiety(int satiety) {
        if (satiety < 0 || satiety > maxSatiety) {
            throw std::invalid_argument("Уровень сытости должен быть в диапазоне от 0 до " + std::to_string(maxSatiety) + "!");
        }
        this->satiety = satiety;
    }

    void setEnergy(int energy) {
        if (energy < 0 || energy > maxEnergy) {
            throw std::invalid_argument("Уровень энергии должен быть в диапазоне от 0 до " + std::to_string(maxEnergy) + "!");
        }
        this->energy = energy;
    }

    void setHealth(int health) {
        if (health < 0 || health > maxHealth) {
            throw std::invalid_argument("Уровень здоровья должен быть в диапазоне от 0 до " + std::to_string(maxHealth) + "!");
        }
        this->health = health;
    }

    void setMood(Mood mood) {
        this->mood = mood;
    }

    static const int maxEnergy = 100;
    static const int maxHealth = 100;
    static const int maxSatiety = 100;
};
