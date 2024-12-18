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
#include "SoundBehavior.h"
#include "MoveBehavior.h"

//����������� ����� �������
class Pet : public Object {
    friend class Owner;
protected:
    std::string name;
    int age;
    Status* status = new Status();
    Sex sex;
    SoundBehavior* soundBehavior = nullptr; //������������� ���������
    MoveBehavior* moveBehavior = nullptr; //������������� ���������

    void setSoundBehavior(SoundBehavior* sb) {
        if (soundBehavior != nullptr) 
            delete soundBehavior; //������� ����������� ���������
        soundBehavior = sb;
    }

    void setMoveBehavior(MoveBehavior* mb) {
        if (moveBehavior != nullptr) 
            delete moveBehavior; //������� ����������� ���������
        moveBehavior = mb;
    }

public:
    Pet() : name(""), age(0), sex(MALE) {}
    Pet(const std::string& name, int age, Sex sex, SoundBehavior* sb, MoveBehavior* mb) : Pet() {
        setName(name);
        setAge(age);
        setSex(sex);
        setSoundBehavior(sb);
        setMoveBehavior(mb);
    }

    //����������� �����������
    Pet(const Pet& other)
        : name(other.name), age(other.age), sex(other.sex), soundBehavior(other.soundBehavior), moveBehavior(other.moveBehavior) {
        status = new Status(*other.status);
    }

    virtual ~Pet()
    {
        delete status;
        delete soundBehavior;
        delete moveBehavior;
    }

    void performSound() const {
        if (soundBehavior != nullptr) 
            soundBehavior->makeSound();
        else
            std::cout << "��� ������� �� ����� �������� ������!" << std::endl;
    }

    void performMove() const {
        if (moveBehavior != nullptr)
            moveBehavior->move();
        else
            std::cout << "��� ������� �� ����� ���������!" << std::endl;
    }

    //�������
    virtual std::string getName() const { return name; }
    virtual int getAge() const { return age; }
    virtual const Status& getStatus() const { return *status; }
    virtual Sex getSex() const { return sex; }
    virtual const SoundBehavior& getSound() const { return *soundBehavior; }
    virtual const MoveBehavior& getMove() const { return *moveBehavior; }

    //�������
    virtual void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("��� ������� �� ����� ���� ������.");
        }
        this->name = name;
    }

    virtual void setAge(int age) {
        this->age = age;
    }

    virtual void setStatus(const Status& status) {
        this->status = new Status(status);
    }

    virtual void setSex(Sex sex) {
        this->sex = sex;
    }

    void use(PetItem* item) {
        if (item->getType() == "Food") {
            int newSatiety = status->getSatiety() + item->getValue();
            status->setSatiety(newSatiety);
            if (status->getSatiety() == Status::maxSatiety) {
                status->setMood(HAPPY);
            }
            std::cout << name << " �������(�) " << item->getName() << " � ���(��) ����� ����������." << std::endl;
        }
        else if (item->getType() == "Medicine") {
            status->setHealth(status->getHealth() + item->getValue());
            if (status->getHealth() > Status::maxHealth) {
                status->setHealth(Status::maxHealth);
                status->setMood(HAPPY);
            }
            std::cout << name << " ������(�) " << item->getName() << " � ���(��) �������� ����������." << std::endl;
        }
    }

    void sleep(const PetHouse& house) {
        status->setEnergy(status->getEnergy() + house.getComfortLevel());
        status->setSatiety(status->getSatiety() - sleepHungerCost);
        if (status->getEnergy() > Status::maxEnergy) {
            status->setEnergy(Status::maxEnergy);
        }

        if (status->getEnergy() >= 50) {
            std::cout << name << " ������ ��������(�)!" << std::endl;
            status->setMood(HAPPY);
        }
        else {
            std::cout << name << " �� ����� ������ ��������(�) :(" << std::endl;
            status->setMood(SAD);
        }
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

static bool areFriends(Pet* Pet1, Pet* Pet2)
{
    if (Pet1->getType() == Pet2->getType() && abs(Pet1->age - Pet2->age) <= 2)
    {
        Pet1->status->setMood(HAPPY);
        Pet2->status->setMood(HAPPY);
        std::cout << Pet1->name << " � " << Pet2->name << " - ������!" << std::endl;
        return true;
    }
    else
    {
        Pet1->status->setMood(ANGRY);
        Pet2->status->setMood(ANGRY);
        std::cout << Pet1->name << " � " << Pet2->name << " ������ �� ������!" << std::endl;
        return false;
    }
}