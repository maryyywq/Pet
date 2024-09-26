#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define MAX_LEN 100
#define MAX_ENERGY 100
#define MAX_HEALTH 100
#define MAX_SATIETY 100
#define MAX_COMFORT 10
#define ENERGY_COST 5
#define HEALTH_COST 5
#define SATIETY_COST 10

// ����������� ���������� �������
typedef enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
} Mood;

// ����������� ������
typedef enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
} Weather;

// ��������� �������
typedef struct {
    int satiety;
    int energy;
    int health;
    Mood mood;
} Status;

// �������� �������
typedef struct {
    char name[MAX_LEN];
    int age;
    Status status;
} Pet;

// �������� ������������
typedef struct {
    char medicineName[MAX_LEN];
    int healingPower;
    int cost;
} Medicine;

// �������� ����
typedef struct {
    char foodName[MAX_LEN];
    int nutritionValue;
    int cost;
} Food;

// �������� ����
typedef struct {
    char gameName[MAX_LEN];
    int funValue;
    int energyCost;
} Game;

// �������� �������
typedef struct {
    char ownerName[MAX_LEN];
    int ownerAge;
    int money;
} Owner;

// �������� ���� �������
typedef struct {
    char houseName[MAX_LEN];
    char address[MAX_LEN];
    int comfortLevel;
} PetHouse;

// �������� �������� ���
typedef struct {
    int dayNumber;
    Weather weather;
} GameDay;

// ������������� �������
void initPet(Pet* pet, char* name, int age) {
    strncpy(pet->name, name, MAX_LEN);
    pet->age = age;
    pet->status.satiety = MAX_SATIETY;
    pet->status.energy = MAX_ENERGY / 2;
    pet->status.health = MAX_HEALTH;
    pet->status.mood = HAPPY;
}

// ����� ������ ����������
char* getMoodString(Mood mood) {
    switch (mood) {
    case HAPPY: return "��������(�)";
    case ANGRY: return "������";
    case SAD: return "��������(��)";
    case AFRAID: return "������";
    default: return "����������� ����������";
    }
}

// ����� ������ ������
char* getWeatherString(Weather weather) {
    switch (weather) {
    case SUNNY: return "��������";
    case RAINY: return "��������";
    case WINDY: return "��������";
    case STORM: return "����";
    default: return "����������� ������";
    }
}

// ����������� ���������� � �������
void displayPet(Pet* pet) {
    printf("��� �������: %s\n", pet->name);
    printf("������� �������: %d\n", pet->age);
    printf("�����: %d\n", pet->status.satiety);
    printf("�������: %d\n", pet->status.energy);
    printf("��������: %d\n", pet->status.health);
    printf("����������: %s\n", getMoodString(pet->status.mood));
}

// ������������� �������
void initOwner(Owner* owner, char* name, int age, int money) {
    strncpy(owner->ownerName, name, MAX_LEN);
    owner->ownerAge = age;
    owner->money = money;
}

// ��������� �������
void feedPet(Pet* pet, Food* food) {
    pet->status.satiety += food->nutritionValue;
    if (pet->status.satiety > MAX_SATIETY) pet->status.satiety = MAX_SATIETY;
    printf("%s ����(�) %s � ���(��) ����� ����������.\n", pet->name, food->foodName);
}

// ���� � ��������
void playWithPet(Pet* pet, Game* game) {
    if (pet->status.energy >= game->energyCost) {
        pet->status.mood = HAPPY;
        pet->status.energy -= game->energyCost;
        pet->status.satiety -= SATIETY_COST;
        printf("%s �������(�) � %s � ����� ��������(�)!\n", pet->name, game->gameName);
    }
    else {
        printf("%s ������� �����(�) ��� ����.\n", pet->name);
    }
}

// ������� �������
void healPet(Pet* pet, Medicine* medicine) {
    pet->status.health += medicine->healingPower;
    if (pet->status.health > MAX_HEALTH) pet->status.health = MAX_HEALTH;
    printf("%s ������(�) %s � ���(��) �������� ����������.\n", pet->name, medicine->medicineName);
}

// �������� � ��������
void walkWithPet(Pet* pet, GameDay* day) {
    if (day->weather == STORM || day->weather == RAINY || day->weather == WINDY) {
        pet->status.mood = AFRAID;
        pet->status.health -= HEALTH_COST;
        if (pet->status.health < 0) pet->status.health = 0;
        printf("%s ���������(���), ������ ��� �� ����� ������ ������.\n", pet->name);
    }
    else {
        pet->status.mood = HAPPY;
        printf("%s ������ � ������������ ������� �������.\n", pet->name);
    }
    pet->status.energy -= ENERGY_COST;
    pet->status.satiety -= SATIETY_COST;
    if (pet->status.energy < 0) pet->status.energy = 0;
}

// �������������� ������� �������
void sleepPet (Pet* pet) {
    pet->status.energy = MAX_ENERGY;
    printf("��� ������� %s ������� ������!\n", pet->name);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pet pet;
    Owner owner;
    initPet(&pet, "��������", 3);
    initOwner(&owner, "������",19, 1000);
    Food food = { "����", 30, 10 };
    Game game = { "���", 40, 10 };
    Medicine medicine = { "����������", 20, 15 };
    GameDay day = { 1, SUNNY };

    displayPet(&pet);
    printf("\n");
    walkWithPet(&pet, &day);
    displayPet(&pet);
    printf("\n");
    playWithPet(&pet, &game);
    displayPet(&pet);
    printf("\n");
    feedPet(&pet, &food);
    displayPet(&pet);
    printf("\n");
    day.weather = RAINY;
    walkWithPet(&pet, &day);
    displayPet(&pet);
    printf("\n");
    healPet(&pet, &medicine);
    displayPet(&pet);
    printf("\n");
    sleepPet(&pet);
    displayPet(&pet);

    return 0;
}