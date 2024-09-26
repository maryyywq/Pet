#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
typedef enum Mood //���������� �������
{
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

typedef enum Weather //������
{
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

//��������� ��� �������� �������
typedef struct {
    char name[MAX_LEN]; //��� �������
    int age; //������� �������
    Status status;
} Pet;

//��������� ��� �������� ��������������� ���������� ��� ������� �������
typedef struct {
    char medicineName[MAX_LEN];
    int healingPower;  // ��������� ������� �������� �������� �������
} Medicine;


// ��������� ��� �������� ����
typedef struct {
    char foodName[MAX_LEN]; //�������� ���
    int nutritionValue; // ����������� �������� (����������� �������)
} Food;

// ��������� ��� �������� ����
typedef struct {
    char gameName[MAX_LEN]; //�������� ����
    int funValue;    // ������� ������� ��������� ����
    int energyCost;  // ������� ������� �������� ����
} Game;

// ��������� ��� �������� ������� �������
typedef struct {
    char ownerName[MAX_LEN]; //��� ������� �������
    int ownerAge; //��� �������
    int money; //���������� ����� �������
} Owner;

// ��������� ��� �������� ���� �������
typedef struct {
    char houseName[MAX_LEN]; // �������� ����
    char adress[MAX_LEN]; //����� ����
    int comfortLevel; // ������� �������� (0 - ������, 10 - �������)
} PetHouse;

// ��������� ��� �������� �������� ���
typedef struct {
    int dayNumber; // ����� �������� ���
    Weather weather; //������
} GameDay;

//���������, ������� ��������� ������ ������� ��������� �������
typedef struct {
    int hunger;
    int energy;
    int health;
    Mood mood;
} Status;

// ������������� �������
void initPet(Pet* pet, const char* name, int age) {
    strncpy(pet->name, name, MAX_LEN);
    pet->age = age;
    pet->status.hunger = 0;
    pet->status.energy = 50;
    pet->status.health = 100;
    pet->status.mood = HAPPY;
}

// ����������� ���������� � �������
void displayPet(const Pet* pet) {
    printf("��� �������: %s\n", pet->name);
    printf("������� �������: %d\n", pet->age);
    printf("�����: %d\n", pet->status.hunger);
    printf("�������: %d\n", pet->status.energy);
    printf("��������: %d\n", pet->status.health);
    printf("����������: %d\n", pet->status.mood);
}

// ������������� �������
void initOwner(Owner* owner, const char* name, int age, int money) {
    strncpy(owner->ownerName, name, MAX_LEN);
    owner->ownerAge = age;
    owner->money = money;
}

// ������������� ���
void initFood(Food* food, const char* foodName, int nutritionValue) {
    strncpy(food->foodName, foodName, MAX_LEN);
    food->nutritionValue = nutritionValue;
}

// ��������� �������
void feedPet(Pet* pet, Food* food) {
    pet->status.hunger -= food->nutritionValue;
    if (pet->status.hunger < 0) {
        pet->status.hunger = 0; // ������� ������ �� �������
    }
    printf("%s eats %s\n", pet->name, food->foodName);
}

// ������������� ����
void initGame(Game* game, const char* gameName, int funValue, int energyCost) {
    strncpy(game->gameName, gameName, MAX_LEN);
    game->funValue = funValue;
    game->energyCost = energyCost;
}

// ������ � ��������
void playWithPet(Pet* pet, Game* game) {
    if (pet->status.energy >= game->energyCost) {
        pet->status.mood = HAPPY;
        pet->status.energy -= game->energyCost;
        printf("%s ������ � ����� ��������!\n", pet->name);
    }
    else {
        printf("%s ����� ����� ��� ����!", pet->name);
    }
}

// ������������� �����������
void initMedicine(Medicine* medicine, const char* name, int healingPower) {
    strncpy(medicine->medicineName, name, MAX_LEN);
    medicine->healingPower = healingPower;
}

// ������� �������
void healPet(Pet* pet, Medicine* medicine) {
    pet->status.health += medicine->healingPower;
    if (pet->status.health > 100) {
        pet->status.health = 100; // �������� �� ����� ��������� 100
    }
    printf("%s ������ %s � ��������� ���� �����!\n", pet->name, medicine->medicineName);
}

// ������������� ����
void initPetHouse(PetHouse* house, const char* name, const char* address, int comfortLevel) {
    strncpy(house->houseName, name, MAX_LEN);
    strncpy(house->adress, address, MAX_LEN);
    house->comfortLevel = comfortLevel;
}

// ���������� �������� �������
void increaseComfort(Pet* pet, PetHouse* house) {
    if (house->comfortLevel >= 7) {
        pet->status.mood = HAPPY;
    }
    else {
        pet->status.mood = SAD;
    }
}

// ������������� �������� ���
void initGameDay(GameDay* day, int dayNumber, Weather weather) {
    day->dayNumber = dayNumber;
    day->weather = weather;
}

// ��������� ������ � ������� ���
void processWeather(Pet* pet, GameDay* day) {
    if (day->weather == STORM || day->weather == RAINY || day->weather == WINDY) {
        pet->status.mood = AFRAID;
		printf("%s ����� ������� ��-�� ������ ������!\n", pet->name);
    }
    else if (day->weather == SUNNY) {
        pet->status.mood = HAPPY;
        printf("%s ������������ ��������� ����!\n", pet->name);
    }
}


int main()
{
    return 0;
}
