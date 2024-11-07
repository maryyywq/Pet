#pragma once

// Определение погоды
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

    //Конструктор копирования
    GameDay(const GameDay& other)
        : dayNumber(other.dayNumber), weather(other.weather) {}

    ~GameDay() = default; //Деструктор по умолчанию

    //Геттеры
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    //Сеттеры
    void setDayNumber(int dayNumber) {
        if (dayNumber < 0) {
            throw std::invalid_argument("Номер дня не может быть отрицательным!");
        }
        this->dayNumber = dayNumber;
    }

    void setWeather(Weather weather) {
        this->weather = weather;
    }
};
