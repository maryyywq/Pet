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

//����������� ����� �������
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

    //����������� �����������
    Pet(const Pet& other)
        : name(other.name), age(other.age), status(other.status), sex(other.sex) {
    }

    virtual ~Pet() = default; //����������� ���������� �� ���������

    //�������
    std::string getName() const { return name; }
    int getAge() const { return age; }
    const Status& getStatus() const { return status; }
    Sex getSex() const { return sex; }

    //�������
    void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("��� ������� �� ����� ���� ������.");
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


    virtual void makeSound() const = 0; //����� ����������� �������

    void use(PetItem* item) {
        if (item->getType() == "Food") {
            int newSatiety = status.getSatiety() + item->getValue();
            status.setSatiety(newSatiety);
            if (status.getSatiety() == Status::maxSatiety) {
                status.setMood(HAPPY);
            }
            std::cout << name << " �������(�) " << item->getName() << " � ���(��) ����� ����������." << std::endl;
            makeSound(); //������� ������ ���� ����� ���
        }
        else if (item->getType() == "Medicine") {
            status.setHealth(status.getHealth() + item->getValue());
            if (status.getHealth() > Status::maxHealth) {
                status.setHealth(Status::maxHealth);
                status.setMood(HAPPY);
            }
            std::cout << name << " ������(�) " << item->getName() << " � ���(��) �������� ����������." << std::endl;
        }
    }

    void sleep(PetHouse house) {
        status.setEnergy(status.getEnergy() + house.getComfortLevel());
        status.setSatiety(status.getSatiety() - sleepHungerCost);
        if (status.getEnergy() > Status::maxEnergy) {
            status.setEnergy(Status::maxEnergy);
        }

        if (status.getEnergy() >= 50) {
            std::cout << name << " ������ ��������(�)!" << std::endl;
            status.setMood(HAPPY);
        }
        else {
            std::cout << name << " �� ����� ������ ��������(�) :(" << std::endl;
            status.setMood(SAD);
        }
        makeSound(); //������� ������ ���� ����� ���
    }

    friend bool areFriends(Pet* Pet1, Pet* Pet2);

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

bool areFriends(Pet* Pet1, Pet* Pet2)
{
    if (Pet1->getType() == Pet2->getType() && abs(Pet1->age - Pet2->age) <= 2)
    {
        Pet1->status.setMood(HAPPY);
        Pet2->status.setMood(HAPPY);
        std::cout << Pet1->name << " � " << Pet2->name << " - ������!" << std::endl;
        return true;
    }
    else
    {
        Pet1->status.setMood(ANGRY);
        Pet2->status.setMood(ANGRY);
        std::cout << Pet1->name << " � " << Pet2->name << " ������ �� ������!" << std::endl;
        return false;
    }
}