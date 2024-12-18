#pragma once
#include <string>
#include <iostream>

class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

    // ����������� ���� ��� ������������ ���������� �����
    static int houseCount;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {
        // ����������� ������� ��� �������� ������ ����
        houseCount++;
    }

    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {
        // ����������� ������� ��� �������� ������ ����
        houseCount++;
    }

    // ����������� �����������
    PetHouse(const PetHouse& other)
        : houseName(other.houseName), address(other.address), comfortLevel(other.comfortLevel) {
        // ������� ����������� �� �����, ��� ��� ��� ����� ������������� �������
    }

    ~PetHouse() {
        // ��������� ������� ��� �������� ����
        houseCount--;
    }

    // �������
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    // �������
    void setHouseName(const std::string& hn) { houseName = hn; }
    void setAddress(const std::string& a) { address = a; }
    void setComfortLevel(int cl) { comfortLevel = (cl > maxComfort) ? maxComfort : cl; }

    // ����������� ����� ��� ��������� ���������� �����
    static int getHouseCount() {
        return houseCount;
    }

    static const int maxComfort = 100;
};

// ������������� ������������ ����
int PetHouse::houseCount = 0;
