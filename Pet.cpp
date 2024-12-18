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

    Owner valera("������", 35, 2000);
    Cat* cat = new Cat("�����", 5, FEMALE);
    Dog* dog = new Dog("������", 10, MALE);
    valera.addNewPet(cat);
    valera.addNewPet(dog);
    
    auto pet = valera.getPet("�����");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();
    pet = valera.getPet("������");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();

    areFriends(cat, dog);

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

    std::cout << valera;
    valera += &cat2;
    std::cout << valera;

    Cat* catptr = new Cat("�����", 2, MALE);
    auto catunique = std::unique_ptr<Cat>(catptr);
    //auto catunique2 = std::unique_ptr<Cat>(catptr);
    catunique.release();

    auto catsmartptr = std::shared_ptr<Cat>(catptr);

    {
        //auto catsmartptrnew = std::shared_ptr<Cat>(catptr);
        //�����, ��������� ���� ������� ������ ��� ���� ������, � ����� ������� ������������ catsmartptr �������� � ����������
    }

    auto name = cat2.getName();
    std::cout << name.append(" ������������ ����� ������!") << std::endl;
    std::cout << name.substr(name.find("������������")) << std::endl;
    std::cout << name.replace(name.find("������������"), 8, "����") << std::endl;
    std::cout << name.erase(6) << std::endl;
        
    return 0;
}