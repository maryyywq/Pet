#pragma once
#include <string>
#include <vector>
#include "Pet.h"

class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;
    std::vector<Pet*> pets;
public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}

    //����������� �����������
    Owner(const Owner& other)
        : ownerName(other.ownerName), ownerAge(other.ownerAge), money(other.money) {}

    ~Owner() = default; 

    //�������
    std::string getName() const { return this->ownerName; }
    int getAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }
    const std::vector<Pet*>& getPets() const { return this->pets; }

    //�������
    void setOwnerName(const std::string& ownerName) {
        if (ownerName.empty()) {
            throw std::invalid_argument("��� ��������� �� ����� ���� ������!");
        }
        this->ownerName = ownerName;
    }

    void setOwnerAge(int ownerAge) {
        if (ownerAge < 0) {
            throw std::invalid_argument("������� ��������� �� ����� ���� �������������!");
        }
        this->ownerAge = ownerAge;
    }

    void setMoney(int money) {
        if (money < 0) {
            throw std::invalid_argument("���������� ����� �� ����� ���� �������������!");
        }
        this->money = money;
    }

    void addNewPet(Pet* pet) { pets.push_back(pet); }
    void removePet(Pet* pet) {
        int index = -1;
        for (int i = 0; i < pets.size(); i++)
        {
            if (pets[i] == pet) {
                index = i;
                break;
            }
        }
        if (index != -1) pets.erase(pets.cbegin() + index);
        else std::cout << "������ ������� � ����� ������� ���!" << std::endl;
    }
    Pet* getPet(std::string name) {
        for (int i = 0; i < pets.size(); i++)
        {
            if (pets[i]->getName() == name) {
                return pets[i];
            }
        }
        std::cout << "������ ������� � ����� ������� ���!" << std::endl;
        return nullptr;
    }

    Owner& operator+=(Pet* newpet) {
        addNewPet(newpet);
        return *this;
    }

    void walk(std::string name, Weather weather) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (weather == STORM || weather == RAINY || weather == WINDY) {
            mypet->status.setMood(AFRAID);
            mypet->status.setHealth(mypet->status.getHealth() - mypet->healthCost);
            if (mypet->status.getHealth() < 0) mypet->status.setHealth(0);
            std::cout << name << " ���������(���) ��-�� ������ ������." << std::endl;
        }
        else {
            mypet->status.setMood(HAPPY);
            std::cout << name << " ������ � ������������ ������� �������." << std::endl;
        }
        mypet->status.setEnergy(mypet->status.getEnergy() - mypet->walkEnergyCost);
        mypet->status.setSatiety(mypet->status.getSatiety() - mypet->satietyCost);
        if (mypet->status.getEnergy() < 0) mypet->status.setEnergy(0);

        mypet->makeSound(); //������� ������ ���� ����� ��������
    }

    void play(std::string name, Game game) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (mypet->status.getEnergy() >= game.getEnergyCost()) {
            mypet->status.setMood(HAPPY);
            mypet->status.setEnergy(mypet->status.getEnergy() - game.getEnergyCost());
            mypet->status.setSatiety(mypet->status.getSatiety() - mypet->satietyCost);
            std::cout << name << " �������(�) � ����� ��������(�)!" << std::endl;
            mypet->makeSound(); //������� ������ ���� ����� ����
        }
        else {
            std::cout << name << " ������� �����(�) ��� ����." << std::endl;
        }
    }
}; 

std::ostream& operator<<(std::ostream& stream, const Owner& owner) {
    stream << "��� ���������: " << owner.getName() << std::endl;
    stream << "�������: " << owner.getAge() << std::endl;
    stream << "���������� �����: " << owner.getMoney() << std::endl;
    stream << "�������: " << std::endl;
    for (int i = 0; i < owner.getPets().size(); i++)
    {
        stream << "\t" << owner.getPets()[i]->getName() << std::endl;
    }
    return stream;
}