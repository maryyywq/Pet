#pragma once
#include "Mood.h"

//����� ��������� �������
class Status {
private:
    int satiety;
    int energy;
    int health;
    Mood mood;

public:
    Status() : satiety(maxSatiety), energy(maxEnergy / 2), health(maxHealth), mood(HAPPY) {}
    ~Status() = default; //���������� �� ���������

    //�������
    int getSatiety() const { return satiety; }
    int getEnergy() const { return energy; }
    int getHealth() const { return health; }
    Mood getMood() const { return mood; }

    //�������
    void setSatiety(int s) { satiety = (s > maxSatiety) ? maxSatiety : s; }
    void setEnergy(int e) { energy = (e > maxEnergy) ? maxEnergy : e; }
    void setHealth(int h) { health = (h > maxHealth) ? maxHealth : h; }
    void setMood(Mood m) { mood = m; }

    static const int maxEnergy = 100;
    static const int maxHealth = 100;
    static const int maxSatiety = 100;
};