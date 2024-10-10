#pragma once
#include <string>

enum Mood {
    HAPPY,
    ANGRY,
    SAD,
    AFRAID
};

static std::string getMoodString(Mood mood) {
    switch (mood) {
    case HAPPY: return "��������(�)";
    case ANGRY: return "������";
    case SAD: return "��������(��)";
    case AFRAID: return "������";
    default: return "����������� ����������";
    }
}