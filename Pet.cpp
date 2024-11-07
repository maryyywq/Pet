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

    Owner valera("Валера", 35, 2000);
    Cat* cat = new Cat("Чешка", 5, FEMALE);
    Dog* dog = new Dog("Мухтар", 10, MALE);
    valera.addNewPet(cat);
    valera.addNewPet(dog);
    
    auto pet = valera.getPet("Чешка");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();
    pet = valera.getPet("Мухтар");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();

    areFriends(cat, dog);

    Cat cat2("Барсик", 4, MALE);
    Dog dog2("Сима", 3, FEMALE);
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
    
    return 0;
}