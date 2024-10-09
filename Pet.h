#pragma once
#include <iostream>
#include <string>

const int MAX_ENERGY = 100;
const int MAX_HEALTH = 100;
const int MAX_SATIETY = 100;
const int MAX_COMFORT = 100;
const int ENERGY_COST = 5;
const int HEALTH_COST = 5;
const int SATIETY_COST = 10;
const int SLEEP_HUNGER_COST = 40;

// ����������� ���������� �������
enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

// ����������� ������
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

// ����� ��������� �������
class Status {
private:
    int satiety;
    int energy;
    int health;
    Mood mood;

public:
    Status() : satiety(MAX_SATIETY), energy(MAX_ENERGY / 2), health(MAX_HEALTH), mood(HAPPY) {}
    ~Status() = default; // ���������� �� ���������

    // �������
    int getSatiety() const { return satiety; }
    int getEnergy() const { return energy; }
    int getHealth() const { return health; }
    Mood getMood() const { return mood; }

    // �������
    void setSatiety(int s) { satiety = (s > MAX_SATIETY) ? MAX_SATIETY : s; }
    void setEnergy(int e) { energy = (e > MAX_ENERGY) ? MAX_ENERGY : e; }
    void setHealth(int h) { health = (h > MAX_HEALTH) ? MAX_HEALTH : h; }
    void setMood(Mood m) { mood = m; }
};

// ����������� ����� �������
class Pet {
protected:
    std::string name;
    int age;
    Status status;

public:
    Pet() : name(""), age(0), status() {}
    Pet(const std::string& name, int age) : name(name), age(age), status() {}
    virtual ~Pet() = default; // ����������� ���������� �� ���������

    // �������
    std::string getName() const { return name; }
    int getAge() const { return age; }
    Status getStatus() const { return status; }

    // �������
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setStatus(const Status& s) { status = s; }

    virtual void makeSound() const = 0; // ����� ����������� �������
    void display() const {
        std::cout << "��� �������: " << name << std::endl;
        std::cout << "������� �������: " << age << std::endl;
        std::cout << "�������: " << status.getSatiety() << std::endl;
        std::cout << "�������: " << status.getEnergy() << std::endl;
        std::cout << "��������: " << status.getHealth() << std::endl;
        std::cout << "����������: " << getMoodString(status.getMood()) << std::endl;
    }

    void feed(int nutritionValue) {
        int newSatiety = status.getSatiety() + nutritionValue;
        status.setSatiety(newSatiety);
        if (status.getSatiety() == MAX_SATIETY) {
            status.setMood(HAPPY);
        }
        std::cout << name << " �������(�) � ���(��) ����� ����������.\n";
        makeSound(); // ������� ������ ���� ����� ���
    }

    void play(int energyCost) {
        if (status.getEnergy() >= energyCost) {
            status.setMood(HAPPY);
            status.setEnergy(status.getEnergy() - energyCost);
            status.setSatiety(status.getSatiety() - SATIETY_COST);
            std::cout << name << " �������(�) � ����� ��������(�)!\n";
            makeSound(); // ������� ������ ���� ����� ����
        }
        else {
            std::cout << name << " ������� �����(�) ��� ����.\n";
        }
    }

    void heal(int healingPower) {
        status.setHealth(status.getHealth() + healingPower);
        if (status.getHealth() > MAX_HEALTH) {
            status.setHealth(MAX_HEALTH);
            status.setMood(HAPPY);
        }
        std::cout << name << " ������(�) ��������� � ���(��) �������� ����������.\n";
    }

    void walk(Weather weather) {
        if (weather == STORM || weather == RAINY || weather == WINDY) {
            status.setMood(AFRAID);
            status.setHealth(status.getHealth() - HEALTH_COST);
            if (status.getHealth() < 0) status.setHealth(0);
            std::cout << name << " ���������(���) ��-�� ������ ������.\n";
        }
        else {
            status.setMood(HAPPY);
            std::cout << name << " ������ � ������������ ������� �������.\n";
        }
        status.setEnergy(status.getEnergy() - ENERGY_COST);
        status.setSatiety(status.getSatiety() - SATIETY_COST);
        if (status.getEnergy() < 0) status.setEnergy(0);

        makeSound(); // ������� ������ ���� ����� ��������
    }

    void sleep(int comfortLevel) {
        status.setEnergy(status.getEnergy() + comfortLevel);
        status.setSatiety(status.getSatiety() - SLEEP_HUNGER_COST);
        if (status.getEnergy() > MAX_ENERGY) {
            status.setEnergy(MAX_ENERGY);
        }

        if (status.getEnergy() >= 50) {
            std::cout << name << " ������ ��������!\n";
            status.setMood(HAPPY);
        }
        else {
            std::cout << name << " �� ����� ������ �������� :(\n";
            status.setMood(SAD);
        }
        makeSound(); // ������� ������ ���� ����� ���
    }

private:
    std::string getMoodString(Mood mood) const {
        switch (mood) {
        case HAPPY: return "��������(�)";
        case ANGRY: return "������";
        case SAD: return "��������(��)";
        case AFRAID: return "������";
        default: return "����������� ����������";
        }
    }
};

// ����� �����
class Cat : public Pet {
public:
    Cat() : Pet() {}
    Cat(const std::string& name, int age) : Pet(name, age) {}
    ~Cat() = default; // ���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }
};

// ����� ������
class Dog : public Pet {
public:
    Dog() : Pet() {}
    Dog(const std::string& name, int age) : Pet(name, age) {}
    ~Dog() = default; // ���������� �� ���������

    void makeSound() const override {
        std::cout << name << " �������: ���!" << std::endl;
    }
};

// ����� ���
class Food {
private:
    std::string foodName;
    int nutritionValue;
    int cost;

public:
    Food() : foodName(""), nutritionValue(0), cost(0) {}
    Food(const std::string& foodName, int nutritionValue, int cost)
        : foodName(foodName), nutritionValue(nutritionValue), cost(cost) {}
    ~Food() = default; // ���������� �� ���������

    // �������
    std::string getFoodName() const { return foodName; }
    int getNutritionValue() const { return nutritionValue; }
    int getCost() const { return cost; }

    // �������
    void setFoodName(const std::string& fn) { foodName = fn; }
    void setNutritionValue(int nv) { nutritionValue = nv; }
    void setCost(int c) { cost = c; }
};

// ����� ���������
class Medicine {
private:
    std::string medicineName;
    int healingPower;
    int cost;

public:
    Medicine() : medicineName(""), healingPower(0), cost(0) {}
    Medicine(const std::string& medicineName, int healingPower, int cost)
        : medicineName(medicineName), healingPower(healingPower), cost(cost) {}
    ~Medicine() = default; // ���������� �� ���������

    // �������
    std::string getMedicineName() const { return medicineName; }
    int getHealingPower() const { return healingPower; }
    int getCost() const { return cost; }

    // �������
    void setMedicineName(const std::string& mn) { medicineName = mn; }
    void setHealingPower(int hp) { healingPower = hp; }
    void setCost(int c) { cost = c; }
};

// ����� ����
class Game {
private:
    std::string gameName;
    int funValue;
    int energyCost;

public:
    Game() : gameName(""), funValue(0), energyCost(0) {}
    Game(const std::string& gameName, int funValue, int energyCost)
        : gameName(gameName), funValue(funValue), energyCost(energyCost) {}
    ~Game() = default; // ���������� �� ���������

    // �������
    std::string getGameName() const { return gameName; }
    int getFunValue() const { return funValue; }
    int getEnergyCost() const { return energyCost; }

    // �������
    void setGameName(const std::string& gn) { gameName = gn; }
    void setFunValue(int fv) { funValue = fv; }
    void setEnergyCost(int ec) { energyCost = ec; }
};

// ����� �������
class Owner {
private:
    std::string ownerName;
    int ownerAge;
    int money;

public:
    Owner() : ownerName(""), ownerAge(0), money(0) {}
    Owner(const std::string& ownerName, int ownerAge, int money)
        : ownerName(ownerName), ownerAge(ownerAge), money(money) {}
    ~Owner() = default; // ���������� �� ���������

    // �������
    std::string getOwnerName() const { return ownerName; }
    int getOwnerAge() const { return ownerAge; }
    int getMoney() const { return money; }

    // �������
    void setOwnerName(const std::string& on) { ownerName = on; }
    void setOwnerAge(int oa) { ownerAge = oa; }
    void setMoney(int m) { money = m; }
};

// ����� ���� �������
class PetHouse {
private:
    std::string houseName;
    std::string address;
    int comfortLevel;

public:
    PetHouse() : houseName(""), address(""), comfortLevel(0) {}
    PetHouse(const std::string& houseName, const std::string& address, int comfortLevel)
        : houseName(houseName), address(address), comfortLevel(comfortLevel) {}
    ~PetHouse() = default; // ���������� �� ���������

    // �������
    std::string getHouseName() const { return houseName; }
    std::string getAddress() const { return address; }
    int getComfortLevel() const { return comfortLevel; }

    // �������
    void setHouseName(const std::string& hn) { houseName = hn; }
    void setAddress(const std::string& a) { address = a; }
    void setComfortLevel(int cl) { comfortLevel = cl; }
};

// ����� �������� ���
class GameDay {
private:
    int dayNumber;
    Weather weather;

public:
    GameDay() : dayNumber(0), weather(SUNNY) {}
    GameDay(int dayNumber, Weather weather)
        : dayNumber(dayNumber), weather(weather) {}
    ~GameDay() = default; // ���������� �� ���������

    // �������
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    // �������
    void setDayNumber(int dn) { dayNumber = dn; }
    void setWeather(Weather w) { weather = w; }
};
