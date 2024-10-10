#pragma once
#include <string>

//����� �������
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}
    ~Owner() = default; //���������� �� ���������

    //�������
    std::string getOwnerName() const { return ownerName; }
    int getOwnerAge() const { return ownerAge; }
    int getMoney() const { return money; }

    //�������
    void setOwnerName(const std::string& on) { ownerName = on; }
    void setOwnerAge(int oa) { ownerAge = oa; }
    void setMoney(int m) { money = m; }
};