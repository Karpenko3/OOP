#include "header.h"
#include <iostream>

using namespace std;
Smartphone::Smartphone() : model("Xiomi"), battery(10) {
    cout << "--- Створено базовий телефон: " << model << " ---" << endl;
}

Smartphone::Smartphone(string m, int b) {
    model = m;
    battery = b;
    cout << "--- Створено новий телефон: " << model << " ---" << endl; 
}

Smartphone::~Smartphone() {
    cout << "[Вимкнення] Телефон " << model << " відключається. Деструктор спрацював!" << endl;
}


void Smartphone::call(int count){
  cout << "Дзвонимо з телефону " << model << "..." << endl;
  for (int i = 1; i <= count; i++){
    if (battery >= 10){
      battery = battery - 10;
    }
    else{
      cout << "Недостатньо заряду для такої кількості дзвінків!" << endl;
    }
  }
}

void Smartphone::check_battery(){
  cout << "Заряд батареї: " << battery << "%" << endl;
}

void Smartphone::charge(int amount){
battery = battery + amount;
  if (battery > 100) { 
        battery = 100;
        cout << "Ваш телефон заряджений повністю!" << endl;
    }
}