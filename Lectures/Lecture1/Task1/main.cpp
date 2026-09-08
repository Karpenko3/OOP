#include <iostream>
#include "header.h"
using namespace std;

int main(){
Smartphone my_phone; 
    
    my_phone.setup("Samsung", 100);
    
    int calls; 
    cout << "\n Привіт! Ось твій новий телефон!" << endl;
    cout << "Скільки дзвінків ви хочете зробити з телефону? Введіть кількість дзвінків: ";
    cin >> calls;
    my_phone.call(calls);
    my_phone.check_battery();

    int charge_amount; 
    cout << "\n Підключено зарядний пристрій." << endl;
    cout << "На скільки відсотків ви хочете зарядити телефон? Введіть число: ";
    cin >> charge_amount;
    
    my_phone.charge(charge_amount);
    my_phone.check_battery();
    return 0;
}