#pragma once
#include <iostream>
#include "SoundBehavior.h"

class MeowBehavior : public SoundBehavior {
public:
    void makeSound() const override {
        std::cout << "Ìÿó!" << std::endl;
    }
};