#pragma once
#include <string>
#include <vector>
#include "Pet.h"
#include <map>
#include <algorithm>

class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;
    std::map<std::string, Pet*> pets; 
    std::vector<PetItem*> itemInventory;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
    {
        setOwnerName(ownerName);
        setOwnerAge(ownerAge);
        setMoney(money);
    }

    //������ ������������� �����������
    Owner(const Owner&) = delete;
    void operator=(const Owner&) = delete;

    ~Owner() = default; 

    //�������
    std::string getName() const { return this->ownerName; }
    int getAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }
    const std::map<std::string, Pet*>& getPets() const { return this->pets; }
    const std::vector<PetItem*>& getInventory() const { return this->itemInventory; }

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

    void addPet(Pet* pet) { 
        pets[pet->name] = pet; 
    }

    void removePet(std::string name) {
        pets.erase(name);
    }

    Pet* getPet(std::string name) {
        auto pet = pets[name];
        if (pet == nullptr)
            std::cout << "������ ������� � ����� ������� ���!" << std::endl;
        return pet;
    }

    void addItem(PetItem* item) {
        itemInventory.push_back(item);
    }

    void removeItem(std::string name) {
        auto it = std::find_if(itemInventory.begin(), itemInventory.end(), [&name](PetItem const& item) {
            return item.getName() == name;
        });

        if (it != itemInventory.end()) itemInventory.erase(it);
        else std::cout << "������ �������� �� ����������!" << std::endl;
    }

    PetItem* getItem(std::string name) {
        auto it = std::find_if(itemInventory.begin(), itemInventory.end(), [&name](PetItem const& item) {
            return item.getName() == name;
        });

        if (it != itemInventory.end()) {
            return *it;
        }
        std::cout << "������ �������� �� ����������!" << std::endl;
        return nullptr;
    }

    void sortItemsByValue() {
        std::sort(itemInventory.begin(), itemInventory.end(), [](const PetItem& left, const PetItem& right) {
            return left.getValue() > right.getValue();
        });
    }

    void sortItemsByCost() {
        std::sort(itemInventory.begin(), itemInventory.end(), [](const PetItem& left, const PetItem& right) {
            return left.getCost() > right.getCost();
        });
    }

    Owner& operator+=(Pet* newpet) {
        addPet(newpet);
        return *this;
    }

    void walk(std::string name, Weather weather) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (weather == STORM || weather == RAINY || weather == WINDY) {
            mypet->status->setMood(AFRAID);
            mypet->status->setHealth(mypet->status->getHealth() - mypet->healthCost);
            if (mypet->status->getHealth() < 0) mypet->status->setHealth(0);
            std::cout << name << " ���������(���) ��-�� ������ ������." << std::endl;
        }
        else {
            mypet->status->setMood(HAPPY);
            std::cout << name << " ������ � ������������ ������� �������." << std::endl;
        }
        mypet->status->setEnergy(mypet->status->getEnergy() - mypet->walkEnergyCost);
        mypet->status->setSatiety(mypet->status->getSatiety() - mypet->satietyCost);
        if (mypet->status->getEnergy() < 0) mypet->status->setEnergy(0);
    }

    void play(std::string name, Game game) {
        auto mypet = getPet(name);

        if (mypet == nullptr) return;

        if (mypet->status->getEnergy() >= game.getEnergyCost()) {
            mypet->status->setMood(HAPPY);
            mypet->status->setEnergy(mypet->status->getEnergy() - game.getEnergyCost());
            mypet->status->setSatiety(mypet->status->getSatiety() - mypet->satietyCost);
            std::cout << name << " �������(�) � ����� ��������(�)!" << std::endl;
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
    for (auto& pair : owner.getPets())
    {
        stream << "\t" << pair.first << std::endl;
    }
    return stream;
}