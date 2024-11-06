#pragma once
#include <string>

// ����� �������
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}

    // ����������� �����������
    Owner(const Owner& other)
        : ownerName(other.ownerName), ownerAge(other.ownerAge), money(other.money) {}

    ~Owner() = default; // ���������� �� ���������

    // �������
    std::string getOwnerName() const { return this->ownerName; }
    int getOwnerAge() const { return this->ownerAge; }
    int getMoney() const { return this->money; }

    // �������
    void setOwnerName(const std::string& on) { this->ownerName = on; }
    void setOwnerAge(int oa) { this->ownerAge = oa; }
    void setMoney(int m) { this->money = m; }
};
