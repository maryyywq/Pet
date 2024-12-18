#pragma once
#include <iostream>
#include <string>
#include "Status.h"
#include "PetHouse.h"
#include "GameDay.h"
#include "Owner.h"
#include "Game.h"
#include "Medicine.h"
#include "Food.h"
#include "PetItem.h"
#include "Mood.h"

// ����������� ����� �������
class Pet {
protected:
    std::string name;
    int age;
    Status status;

public:
    Pet() : name(""), age(0), status() {}
    Pet(const std::string& name, int age) : name(name), age(age), status() {}

    // ����������� �����������
    Pet(const Pet& other)
        : name(other.name), age(other.age), status(other.status) {
    }

    virtual ~Pet() = default; // ����������� ���������� �� ���������

    // �������
    std::string getName() const { return this->name; }
    int getAge() const { return this->age; }
    Status getStatus() const { return this->status; }

    // �������
    void setName(const std::string& n) { this->name = n; }
    void setAge(int a) { this->age = a; }
    void setStatus(const Status& s) { this->status = s; }

    virtual void makeSound() const = 0; // ����� ����������� �������

    void use(PetItem* item) {
        if (item->getType() == "Food") {
            int newSatiety = this->status.getSatiety() + item->getValue();
            this->status.setSatiety(newSatiety);
            if (this->status.getSatiety() == Status::maxSatiety) {
                this->status.setMood(HAPPY);
            }
            std::cout << this->name << " �������(�) " << item->getName() << " � ���(��) ����� ����������." << std::endl;
            this->makeSound(); // ������� ������ ���� ����� ���
        }
        else if (item->getType() == "Medicine") {
            this->status.setHealth(this->status.getHealth() + item->getValue());
            if (this->status.getHealth() > Status::maxHealth) {
                this->status.setHealth(Status::maxHealth);
                this->status.setMood(HAPPY);
            }
            std::cout << this->name << " ������(�) " << item->getName() << " � ���(��) �������� ����������." << std::endl;
        }
    }

    void play(Game game) {
        if (this->status.getEnergy() >= game.getEnergyCost()) {
            this->status.setMood(HAPPY);
            this->status.setEnergy(this->status.getEnergy() - game.getEnergyCost());
            this->status.setSatiety(this->status.getSatiety() - satietyCost);
            std::cout << this->name << " �������(�) � ����� ��������(�)!" << std::endl;
            this->makeSound(); // ������� ������ ���� ����� ����
        }
        else {
            std::cout << this->name << " ������� �����(�) ��� ����." << std::endl;
        }
    }

    void walk(Weather weather) {
        if (weather == STORM || weather == RAINY || weather == WINDY) {
            this->status.setMood(AFRAID);
            this->status.setHealth(this->status.getHealth() - healthCost);
            if (this->status.getHealth() < 0) this->status.setHealth(0);
            std::cout << this->name << " ���������(���) ��-�� ������ ������." << std::endl;
        }
        else {
            this->status.setMood(HAPPY);
            std::cout << this->name << " ������ � ������������ ������� �������." << std::endl;
        }
        this->status.setEnergy(this->status.getEnergy() - walkEnergyCost);
        this->status.setSatiety(this->status.getSatiety() - satietyCost);
        if (this->status.getEnergy() < 0) this->status.setEnergy(0);

        this->makeSound(); // ������� ������ ���� ����� ��������
    }

    void sleep(PetHouse house) {
        this->status.setEnergy(this->status.getEnergy() + house.getComfortLevel());
        this->status.setSatiety(this->status.getSatiety() - sleepHungerCost);
        if (this->status.getEnergy() > Status::maxEnergy) {
            this->status.setEnergy(Status::maxEnergy);
        }

        if (this->status.getEnergy() >= 50) {
            std::cout << this->name << " ������ ��������(�)!" << std::endl;
            this->status.setMood(HAPPY);
        }
        else {
            std::cout << this->name << " �� ����� ������ ��������(�) :(" << std::endl;
            this->status.setMood(SAD);
        }
        this->makeSound(); // ������� ������ ���� ����� ���
    }

    static const int walkEnergyCost = 5;
    static const int healthCost = 5;
    static const int satietyCost = 10;
    static const int sleepHungerCost = 40;
};

std::ostream& operator<<(std::ostream& stream, const Pet& pet) {
    stream << "��� �������: " << pet.getName() << std::endl;
    stream << "������� �������: " << pet.getAge() << std::endl;
    stream << "�������: " << pet.getStatus().getSatiety() << std::endl;
    stream << "�������: " << pet.getStatus().getEnergy() << std::endl;
    stream << "��������: " << pet.getStatus().getHealth() << std::endl;
    stream << "����������: " << getMoodString(pet.getStatus().getMood()) << std::endl;
    return stream;
}
