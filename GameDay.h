#pragma once

// ����������� ������
enum Weather {
    SUNNY,
    RAINY,
    WINDY,
    STORM
};

//����� �������� ���
class GameDay {
private:
    int dayNumber;
    Weather weather;

public:
    GameDay() : dayNumber(0), weather(SUNNY) {}
    GameDay(int dayNumber, Weather weather)
        : dayNumber(dayNumber), weather(weather) {}

    //����������� �����������
    GameDay(const GameDay& other)
        : dayNumber(other.dayNumber), weather(other.weather) {}

    ~GameDay() = default; //���������� �� ���������

    //�������
    int getDayNumber() const { return dayNumber; }
    Weather getWeather() const { return weather; }

    //�������
    void setDayNumber(int dayNumber) {
        if (dayNumber < 0) {
            throw std::invalid_argument("����� ��� �� ����� ���� �������������!");
        }
        this->dayNumber = dayNumber;
    }

    void setWeather(Weather weather) {
        this->weather = weather;
    }
};
