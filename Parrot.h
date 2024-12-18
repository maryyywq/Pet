#pragma once
#include <string>
#include "Pet.h"
#include "FlyBehavior.h"
#include "SoundBehavior.h"
#include "TweetBehavior.h"
#include <random>
#include <set>

class Parrot : public Pet {
private:
    std::set<std::string> learntSounds;
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

    void learnNewSound(std::string newSound) {
        srand(time(0));
        if (rand() % 2 == 0 && newSound.length() <= 10) {
            learntSounds.insert(newSound);
            std::cout << "��� ������� �������� �������� ����� ����!" << std::endl;
        }
       else 
       {
           std::cout << "��� ������� ������ �� ��������..." << std::endl;
       }
    }

    void makeHumanSound() {
        auto soundsvector = std::vector<std::string>(learntSounds.begin(), learntSounds.end());
        if (soundsvector.empty()) {
            std::cout << "������� ������..." << std::endl;
            return;
        }
        srand(time(0));
        std::cout << soundsvector[rand() % soundsvector.size()] << std::endl;
    }

    std::string getType() const override { return "Parrot"; }
 };