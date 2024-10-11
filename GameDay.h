#pragma once

//Определение погоды
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

//Класс игрового дня
class GameDay {
private:
    int dayNumber;
    Weather weather;

public:
    GameDay() : dayNumber(0), weather(SUNNY) {}
    GameDay(int dayNumber, Weather weather)
        : dayNumber(dayNumber), weather(weather) {}
    ~GameDay() = default; //Деструктор по умолчанию

    //Геттеры
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    //Сеттеры
    void setDayNumber(int dn) { dayNumber = dn; }
    void setWeather(Weather w) { weather = w; }
};
