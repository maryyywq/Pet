#pragma once

class SoundBehavior //����������� ����� 
{
public:
    virtual void makeSound() const = 0;
    virtual ~SoundBehavior() = default;
};

