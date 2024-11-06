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

    Owner valera;
    Cat* cat = new Cat("Чешка", 5);
    Dog* dog = new Dog("Мухтар", 10);
    std::shared_ptr<Cat> catptr{ cat };
    valera.addNewPet(catptr);
    std::shared_ptr<Dog> dogptr{ dog };
    valera.addNewPet(dogptr);
    
    auto pet = valera.getPet("Чешка");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();
    pet = valera.getPet("Мухтар");
    std::cout << pet->getType() << std::endl;
    pet->makeSound();

    areFriends(catptr, dogptr);
    
    return 0;
}