#pragma once
#include <iostream>
#include "MoveBehavior.h"

class FlyBehavior : public MoveBehavior {
public:
    void move() const override {
        std::cout << "��� ������� �������(�)!" << std::endl;
    }
};

