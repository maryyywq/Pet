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
    
    Cat cat1 = Cat("��������", 4, FEMALE);
    Owner valera;
    valera.addNewPet(&cat1);
    valera.walk("��������", SUNNY);
    Cat cat2 = cat1;
    cat1.use(new Food("������", 10, 100));

    std::cout << cat1 << std::endl;
    std::cout << cat2 << std::endl;
        
    Game game{ "��������", 50, 25 };
    Football foot = game;
    foot.play();

    //Owner valera1 = valera;

    Pet* cat3 = new Cat("������ ������������", 5, MALE);
    delete cat3;

    Pet* pet = new Cat();
    pet->setAge(26);

    return 0;
}