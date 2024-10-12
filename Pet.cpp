#include <Windows.h>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Football.h"
#include "LaserPointer.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Работа со статическими данными:" << std::endl;

    //Создаем владельца
    Owner owner("Мария", 19, 500);

    //Создаем дом для питомцев
    PetHouse petHouse("Теплая постель хозяйки", "Ленина, 59", 75);

    //Создаем питомцев
    Cat myCat("Чешулька", 3);
    Dog myDog("Белка", 5);

    //Создаем игры для питомцев
    Game catGame("Мышеловка", 20, 15);
    Game dogGame("Мячик", 25, 10);

    //Создаем еду для питомцев
    Food catFood("Корм для кошек", 20, 5);
    Food dogFood("Корм для собак", 30, 8);

    //Создаем медикаменты для питомцев
    Medicine medicine("Витаминки", 15, 10);

    //Питомцы гуляют
    std::cout << "Питомцы идут на прогулку:" << std::endl;
    myCat.walk(SUNNY);
    myDog.walk(RAINY);

    //Выводим информацию о питомцах
    std::cout << std::endl << "Информация о питомцах:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //Питомцы едят
    std::cout << std::endl << "Питомцы едят:" << std::endl;
    myCat.use(&catFood);
    myDog.use(&dogFood);

    //Выводим информацию о питомцах
    std::cout << std::endl << "Информация о питомцах:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //Питомцы играют
    std::cout << std::endl << "Питомцы играют:" << std::endl;
    myCat.play(catGame);
    myDog.play(dogGame);

    //Выводим информацию о питомцах
    std::cout << std::endl << "Информация о питомцах:" << std::endl;
    std::cout << myCat << std::endl;
    std::cout << myDog;

    //Питомцы спят
    std::cout << std::endl << "Питомцы отдыхают:" << std::endl;
    myCat.sleep(petHouse);
    myDog.sleep(petHouse);

    //Питомцы лечатся
    std::cout << std::endl << "Питомцы принимают лекарства:" << std::endl;
    myCat.use(&medicine);
    myDog.use(&medicine);

    std::cout << std::endl << "Пример работы с динамическим массивом Cat:" << std::endl;
    Cat* catsArray = new Cat[2];
    catsArray[0].setName("Чернушка");
    catsArray[1].setName("Маруся");
    catsArray[0].makeSound();
    catsArray[1].makeSound();
    catsArray[0].walk(SUNNY);
    catsArray[1].getStatus();
    delete[] catsArray;

    std::cout << std::endl << "Пример работы с массивом динамических объектов Pet:" << std::endl;
    Pet* petsArray[2];
    petsArray[0] = new Cat();
    petsArray[0]->setName("Санек");
    petsArray[1] = new Dog();
    petsArray[1]->setName("Бобик");

    petsArray[0]->makeSound();
    petsArray[1]->makeSound();

    //Создаем еду для питомцев
    Food catFood2("Корм для кошек", 20, 5);
    Food dogFood2("Корм для собак", 30, 8);
    petsArray[0]->use(&catFood2);
    petsArray[0]->use(&dogFood2);
    for (size_t i = 0; i < 2; i++) delete petsArray[i];

    
    Game* pointerGame;
    std::cout << std::endl;
    pointerGame = new Game();
    pointerGame->play();
    delete pointerGame;
    pointerGame = new Football();
    pointerGame->play();
    delete pointerGame;
    pointerGame = new LaserPointer();
    pointerGame->play();
    return 0;
}