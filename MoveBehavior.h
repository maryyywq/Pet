#pragma once

class MoveBehavior {
public:
    virtual void move() const = 0;
    virtual ~MoveBehavior() = default;
};