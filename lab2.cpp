#include <Windows.h>
#include "Pet.h"

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
    Medicine medicine("���������", 15, 10);

    //������� ������
    std::cout << "������� ���� �� ��������:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    //������� ����
    std::cout << std::endl << "������� ����:" << std::endl;
    myCat.use(&catFood);
    myDog.use(&dogFood);

    //������� ������
    std::cout << std::endl << "������� ������:" << std::endl;
    myCat.play(catGame);
    myDog.play(dogGame);

    //������� ����
    std::cout << std::endl << "������� ��������:" << std::endl;
    myCat.sleep(petHouse);
    myDog.sleep(petHouse);

    //������� �������
    std::cout << std::endl << "������� ��������� ���������:" << std::endl;
    myCat.use(&medicine);
    myDog.use(&medicine);

    // ������� ���������� � ��������
    std::cout << std::endl << "���������� � ��������:" << std::endl;
    std::cout << myCat;
    std::cout << myDog;

    return 0;
}
