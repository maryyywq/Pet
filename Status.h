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
    Status() : satiety(maxSatiety), energy(maxEnergy / 2), health(maxHealth), mood(HAPPY) {}

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
    void setSatiety(int satiety) { this->satiety = (satiety > this->maxSatiety) ? this->maxSatiety : satiety; }
    void setEnergy(int energy) { this->energy = (energy > this->maxEnergy) ? this->maxEnergy : energy; }
    void setHealth(int health) { this->health = (health > this->maxHealth) ? this->maxHealth : health; }
    void setMood(Mood mood) { this->mood = mood; }

    static const int maxEnergy = 100;
    static const int maxHealth = 100;
    static const int maxSatiety = 100;
};
