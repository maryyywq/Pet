#pragma once
#include <iostream>
#include "SoundBehavior.h"

class TweetBehavior : public SoundBehavior {
public:
    void makeSound() const override {
        std::cout << "Чик-чирик!" << std::endl;
    }
};