#include "Pet.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // ������� ���������
    Owner owner("�����", 19, 500);

    // ������� ��� ��� ��������
    PetHouse petHouse("������ ������� �������", "������, 59", 75);

    // ������� ��������
    Cat myCat("��������", 3);
    Dog myDog("�����", 5);

    // ������� ���� ��� ��������
    Game catGame("���������", 20, 15);
    Game dogGame("�����", 25, 10);

    // ������� ��� ��� ��������
    Food catFood("���� ��� �����", 20, 5);
    Food dogFood("���� ��� �����", 30, 8);

    // ������� ����������� ��� ��������
    Medicine catMedicine("�������� ��� �����", 15, 10);
    Medicine dogMedicine("�������� ��� �����", 20, 12);

    // ������� ������
    std::cout << "������� ���� �� ��������:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    // ������� ����
    std::cout << "������ ��������:" << std::endl;
    if (owner.getMoney() >= catFood.getCost()) {
        myCat.feed(catFood.getNutritionValue());
        owner.setMoney(owner.getMoney() - catFood.getCost()); // ��������� ������ ���������
        std::cout << owner.getOwnerName() << " ��������(�) " << catFood.getCost() << " �� " << catFood.getFoodName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " ������������ ����� ��� ������� " << catFood.getFoodName() << "." << std::endl;
    }

    if (owner.getMoney() >= dogFood.getCost()) {
        myDog.feed(dogFood.getNutritionValue());
        owner.setMoney(owner.getMoney() - dogFood.getCost()); // ��������� ������ ���������
        std::cout << owner.getOwnerName() << " ��������(�) " << dogFood.getCost() << " �� " << dogFood.getFoodName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " ������������ ����� ��� ������� " << dogFood.getFoodName() << "." << std::endl;
    }

    // ������� ������
    std::cout << "������� ������:" << std::endl;
    myCat.play(catGame.getEnergyCost());
    myDog.play(dogGame.getEnergyCost());

    // ������� ����
    std::cout << "������� ��������:" << std::endl;
    myCat.sleep(30);
    myDog.sleep(40);

    // ������� �������
    std::cout << "������� ��������� ���������:" << std::endl;
    if (owner.getMoney() >= catMedicine.getCost()) {
        myCat.heal(catMedicine.getHealingPower());
        owner.setMoney(owner.getMoney() - catMedicine.getCost()); // ��������� ������ ���������
        std::cout << owner.getOwnerName() << " ��������(�) " << catMedicine.getCost() << " �� " << catMedicine.getMedicineName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " ������������ ����� ��� ������� " << catMedicine.getMedicineName() << "." << std::endl;
    }

    if (owner.getMoney() >= dogMedicine.getCost()) {
        myDog.heal(dogMedicine.getHealingPower());
        owner.setMoney(owner.getMoney() - dogMedicine.getCost()); // ��������� ������ ���������
        std::cout << owner.getOwnerName() << " ��������(�) " << dogMedicine.getCost() << " �� " << dogMedicine.getMedicineName() << "." << std::endl;
    }
    else {
        std::cout << owner.getOwnerName() << " ������������ ����� ��� ������� " << dogMedicine.getMedicineName() << "." << std::endl;
    }

    // ������� ���������� � �������� � � ������� ���������
    std::cout << std::endl << "���������� � ��������:" << std::endl;
    myCat.display();
    std::cout << std::endl;
    myDog.display();

    // ������� ���������� � ������� �������
    std::cout << std::endl << owner.getOwnerName() << ", � ��� �������� " << owner.getMoney() << " �����." << std::endl;

    return 0;
}
