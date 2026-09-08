#pragma once
#include <iostream>
#include <cctype>


class MotorDriver{
private:
    int pinA;
    int pinB;
    int speed;
    
public:
    MotorDriver();
    MotorDriver(int pA, int pB);
    ~MotorDriver();
    void set_speed(int pwm_value);
    void forward();
    void stop();
}; 