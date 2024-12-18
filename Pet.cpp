#include <Windows.h>
#include <typeinfo>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Football.h"
#include "LaserPointer.h"
#include "Owner.h"
#include "Parrot.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Pet* myCat = new Cat("Чернь", 3, FEMALE);
    Pet* myParrot = new Parrot("Попка", 4, MALE);

    PetItem* item1 = new Food("Сникерс", 20, 60);
    PetItem* item2 = new Medicine("Нурафен", 40, 50);

    Owner* marina = new Owner("Мария", 19, 1000);

    marina->addPet(myCat);
    marina->addPet(myParrot);
    marina->addItem(item1);
    marina->addItem(item2);
    std::cout << *marina << std::endl;

    Pet* pet1 = marina->getPet("Чернь");
    std::cout << *pet1 << std::endl;
    Pet* pet2 = marina->getPet("Санек");

    marina->sortItemsByValue();
    std::cout << *marina << std::endl;
    marina->sortItemsByCost();
    std::cout << *marina << std::endl;

    Parrot parrot;
    parrot.learnNewSound("Привет!");
    parrot.makeHumanSound();

    return 0;
}