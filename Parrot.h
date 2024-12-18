#pragma once
#include <string>
#include "Pet.h"
#include "FlyBehavior.h"
#include "SoundBehavior.h"
#include "TweetBehavior.h"
#include <random>

class Parrot : public Pet {
public:
    Parrot() : Pet() { setSoundBehavior(new TweetBehavior()), setMoveBehavior(new FlyBehavior); }

    Parrot(const std::string& name, int age, Sex sex) : Pet(name, age, sex, new TweetBehavior(), new FlyBehavior()) {}
    ~Parrot() = default; //���������� �� ���������

    void setAge(int age) override {
        if (age < 0 || age > 10) {
            throw std::invalid_argument("������� ������� ������ ���� � �������� �� 0 �� 10.");
        }
        Pet::setAge(age);
    }

    void learnNewSound(SoundBehavior* newSoundBehavior) {
        srand(time(0));
        if (rand() % 2 == 0) {
            Pet::setSoundBehavior(newSoundBehavior);
            std::cout << "��� ������� �������� �������� ����� ����!" << std::endl;
        }
       else 
       {
           std::cout << "��� ������� ������ �� ��������..." << std::endl;
       }
    }

    std::string getType() const override { return "Parrot"; }

 };