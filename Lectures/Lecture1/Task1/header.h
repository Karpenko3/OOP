#pragma once
#include <iostream>
#include <cctype>


using namespace std;

class Smartphone {

private:
    string model;
    int battery;

public:

void setup(string m, int b);
void call(int count);
void check_battery();
void charge(int amount);

};