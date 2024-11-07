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
    
    std::cout << "Работа с указателями: " << std::endl;
    Owner valera("Валера", 35, 2000);
    Cat* cat = new Cat("Чешка", 5, FEMALE);
    Dog* dog = new Dog("Мухтар", 10, MALE);
    valera.addNewPet(cat);
    valera.addNewPet(dog);
    
    auto pet = valera.getPet("Чешка");
    pet->makeSound();
    pet = valera.getPet("Мухтар");
    pet->makeSound();

    std::cout << std::endl << "Пример дружественной функции: " << std::endl;
    areFriends(cat, dog);

    std::cout << std::endl << "Пример обработки исключений: " << std::endl;
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

    std::cout << std::endl << "Пример перегрузки оператора: " << std::endl;
    std::cout << valera;
    valera += &cat2;
    std::cout << valera;

   //Работа с умными указателями
    Cat* catptr = new Cat("Борис", 2, MALE);
    auto catunique = std::unique_ptr<Cat>(catptr);
    //auto catunique2 = std::unique_ptr<Cat>(catptr);
    //иначе вызовет исключение, тк unique_ptr предполагает единое владение объектом
    catunique.release();

    auto catsmartptr = std::shared_ptr<Cat>(catptr);

    {
        //auto catsmartptrnew = std::shared_ptr<Cat>(catptr);
        //иначе, указатель выше очистит память под кота Бориса, и любая попытка использовать catsmartptr приведет к исключению
    }

    std::cout << std::endl << "Работа со строками: " << std::endl;
    auto name = cat2.getName();
    std::cout << name.append(" наслаждается своей жизнью!") << std::endl;
    std::cout << name.substr(name.find("наслаждается")) << std::endl;
    std::cout << name.replace(name.find("наслаждается"), 8, "раду") << std::endl;
    std::cout << name.erase(6) << std::endl;

    std::cout << std::endl << "Пример конструктора копирования: " << std::endl;
    Cat cat3("Васька", 4, MALE);
    Cat cat4 = cat3; 
    cat4.setName("Феликс");
    std::cout << cat3 << std::endl << cat4 << std::endl;
        
    return 0;
}