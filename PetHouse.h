#pragma once
#include <string>
#include <iostream>

class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

    //����������� ���� ��� ������������ ���������� �����
    static int houseCount;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {
        //����������� ������� ��� �������� ������ ����
        houseCount++;
    }

    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {
        houseCount++;
    }

    //����������� �����������
    PetHouse(const PetHouse& other)
        : houseName(other.houseName), address(other.address), comfortLevel(other.comfortLevel) {
        houseCount++;
    }

    ~PetHouse() {
        //��������� ������� ��� �������� ����
        houseCount--;
    }

    //�������
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    //�������
    void setHouseName(const std::string& houseName) {
        if (houseName.empty()) {
            throw std::invalid_argument("�������� ���� �� ����� ���� ������!");
        }
        this->houseName = houseName;
    }

    void setAddress(const std::string& address) {
        if (address.empty()) {
            throw std::invalid_argument("����� �� ����� ���� ������!");
        }
        this->address = address;
    }

    void setComfortLevel(int comfortLevel) {
        if (comfortLevel < 0 || comfortLevel > maxComfort) {
            throw std::invalid_argument("������� �������� ������ ���� � ��������� �� 0 �� " + std::to_string(maxComfort) + "!");
        }
        this->comfortLevel = comfortLevel;
    }

    //����������� ����� ��� ��������� ���������� �����
    static int getHouseCount() {
        return houseCount;
    }

    static const int maxComfort = 100;
};

//������������� ������������ ����
int PetHouse::houseCount = 0;