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
    
    Pet* myCat = new Cat();
    Pet* myDog = new Dog();
    Pet* myParrot = new Parrot();

    myCat->performSound(); 
    myDog->performSound();
    myParrot->performSound(); 
    ((Parrot*)myParrot)->learnNewSound(new MeowBehavior()); //пытаемс€ научить попуга€ м€укать
    myParrot->performSound(); 

    myCat->performMove(); 
    myDog->performMove();
    myParrot->performMove();

    delete myCat;
    delete myDog;
    delete myParrot;

    return 0;
}