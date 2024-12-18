#include <Windows.h>
#include <typeinfo>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Football.h"
#include "LaserPointer.h"
#include "Owner.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::cout << "������ � �����������: " << std::endl;
    Owner valera("������", 35, 2000);
    Cat* cat = new Cat("�����", 5, FEMALE);
    Dog* dog = new Dog("������", 10, MALE);
    valera.addNewPet(cat);
    valera.addNewPet(dog);
    
    auto pet = valera.getPet("�����");
    pet->makeSound();
    pet = valera.getPet("������");
    pet->makeSound();

    std::cout << std::endl << "������ ������������� �������: " << std::endl;
    areFriends(cat, dog);

    std::cout << std::endl << "������ ��������� ����������: " << std::endl;
    Cat cat2("������", 4, MALE);
    Dog dog2("����", 3, FEMALE);
    try
    {
        auto newcat = *cat + cat2;
        auto newdog = *dog + dog2;
    }
    catch (const std::exception& e)
    {
       std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "������ ���������� ���������: " << std::endl;
    std::cout << valera;
    valera += &cat2;
    std::cout << valera;

   //������ � ������ �����������
    Cat* catptr = new Cat("�����", 2, MALE);
    auto catunique = std::unique_ptr<Cat>(catptr);
    //auto catunique2 = std::unique_ptr<Cat>(catptr);
    //����� ������� ����������, �� unique_ptr ������������ ������ �������� ��������
    catunique.release();

    auto catsmartptr = std::shared_ptr<Cat>(catptr);

    {
        //auto catsmartptrnew = std::shared_ptr<Cat>(catptr);
        //�����, ��������� ���� ������� ������ ��� ���� ������, � ����� ������� ������������ catsmartptr �������� � ����������
    }

    std::cout << std::endl << "������ �� ��������: " << std::endl;
    auto name = cat2.getName();
    std::cout << name.append(" ������������ ����� ������!") << std::endl;
    std::cout << name.substr(name.find("������������")) << std::endl;
    std::cout << name.replace(name.find("������������"), 8, "����") << std::endl;
    std::cout << name.erase(6) << std::endl;

    std::cout << std::endl << "������ ������������ �����������: " << std::endl;
    Cat cat3("������", 4, MALE);
    Cat cat4 = cat3; 
    cat4.setName("������");
    std::cout << cat3 << std::endl << cat4 << std::endl;
        
    return 0;
}