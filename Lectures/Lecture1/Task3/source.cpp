#include "header.h"
#include <iostream>

using namespace std;

MotorDriver:: MotorDriver(){
  cout << "Увага: Двигун створено без прив'язки до пінів!"<< endl;
}

MotorDriver::MotorDriver(int pA, int pB){
    pinA = pA; 
    pinB = pB; 
    speed = 0; 
    cout << "Налаштування пінів [" << pA << "] та [" << pB << "] як OUTPUT" << endl;
}

void MotorDriver::set_speed(int pwm_value){
  if (pwm_value < 0){
    speed = 0;
  } else  if(pwm_value > 255){
    speed = 255;
  }
  else{
    speed = pwm_value;
  }
}

void MotorDriver::forward(){
 cout << "Подаємо ШІМ " << speed << " на пін " << pinA << endl;
}

void MotorDriver:: stop(){
speed = 0;
cout << "Зупинка! ШІМ 0 на обидва піни" << endl;
}

MotorDriver:: ~MotorDriver(){
  void stop();
  cout << "Аварійне відключення пінів! Двигун деініціалізовано." << endl;
} 