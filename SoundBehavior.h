#pragma once

class SoundBehavior //абстрактный класс 
{
public:
    virtual void makeSound() const = 0;
    virtual ~SoundBehavior() = default;
};

