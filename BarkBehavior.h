#pragma once
#include <iostream>
#include "SoundBehavior.h"

class BarkBehavior : public SoundBehavior {
public:
    void makeSound() const override {
        std::cout << "Ãàâ!" << std::endl;
    }
};
