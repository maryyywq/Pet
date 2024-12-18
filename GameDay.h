#pragma once

// ����������� ������
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
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

    // ����������� �����������
    GameDay(const GameDay& other)
        : dayNumber(other.dayNumber), weather(other.weather) {}

    ~GameDay() = default; // ���������� �� ���������

    // �������
    int getDayNumber() const { return this->dayNumber; }
    Weather getWeather() const { return this->weather; }

    // �������
    void setDayNumber(int dn) { this->dayNumber = dn; }
    void setWeather(Weather w) { this->weather = w; }
};
