#pragma once
#include "Mood.h"

// Класс состояния питомца
class Status {
private:
    int satiety;
    int energy;
    int health;
    Mood mood;

public:
    Status() : satiety(this->maxSatiety), energy(this->maxEnergy / 2), health(this->maxHealth), mood(HAPPY) {}

    // Конструктор копирования
    Status(const Status& other)
        : satiety(other.satiety), energy(other.energy), health(other.health), mood(other.mood) {}

    ~Status() = default; // Деструктор по умолчанию

    // Геттеры
    int getSatiety() const { return this->satiety; }
    int getEnergy() const { return this->energy; }
    int getHealth() const { return this->health; }
    Mood getMood() const { return this->mood; }

    // Сеттеры
    void setSatiety(int s) { this->satiety = (s > this->maxSatiety) ? this->maxSatiety : s; }
    void setEnergy(int e) { this->energy = (e > this->maxEnergy) ? this->maxEnergy : e; }
    void setHealth(int h) { this->health = (h > this->maxHealth) ? this->maxHealth : h; }
    void setMood(Mood m) { this->mood = m; }

    static const int maxEnergy = 100;
    static const int maxHealth = 100;
    static const int maxSatiety = 100;
};
