#include "Header.h"
#include <iomanip>



DOG::DOG() : name("Невідома"), weight(0.0), age(0) {}

DOG::DOG(string name, float weight, int age) {
    this->name = name;
    this->weight = weight;
    this->age = age;
}

DOG::DOG(const DOG &other) {
    name = other.name;
    weight = other.weight;
    age = other.age;
}

DOG::~DOG() {} 

void DOG::set_name(string name) { 
    this->name = name; 
}

void DOG::set_weight(float weight) { 
    this->weight = weight; 
}

void DOG::set_age(int age) { 
    this->age = age; 
}

string DOG::get_name() { 
    return name; 
}

float DOG::get_weight() {
    return weight;
}

int DOG::get_age() {
    return age; 
}

void DOG::show() {
    cout << "   - Собака: " << left << setw(15) << name 
         << " | Вік: " << setw(3) << age 
         << " | Вага: " << weight << " кг\n";
}



int MASTER::count = 0; 


MASTER::MASTER() : pib("Невідомий"), club_id(0), dogs(nullptr), num_dogs(0) {
    count++;
}

MASTER::MASTER(string pib, int club_id) : pib(pib), club_id(club_id), dogs(nullptr), num_dogs(0) {
    count++;
}


MASTER::MASTER(const MASTER &other) : pib(other.pib), club_id(other.club_id), num_dogs(other.num_dogs) {
    if (num_dogs > 0) {
        dogs = new DOG[num_dogs];
        for (int i = 0; i < num_dogs; i++) {
            dogs[i] = other.dogs[i]; 
        }
    } else {
        dogs = nullptr;
    }
    count++;
}


MASTER::~MASTER() {
    delete[] dogs;
    count--;
}

void MASTER::set_pib(string pib) { 
    this->pib = pib;
}
string MASTER::get_pib() { 
    return pib; 
}

int MASTER::get_club_id() { 
    return club_id; 
}

int MASTER::get_count() { 
    return count; 
}


void MASTER::add_dog(const DOG &new_dog) {
    DOG* temp = new DOG[num_dogs + 1]; 
    
    for (int i = 0; i < num_dogs; i++) {
        temp[i] = dogs[i]; 
    }
    temp[num_dogs] = new_dog;
    
    delete[] dogs; 
    dogs = temp;   
    num_dogs++;
}

void MASTER::show() {
    cout << "\nВласник: " << pib << " (ID Клубу: " << club_id << ")\n";
    if (num_dogs == 0) {
        cout << "   - Немає зареєстрованих собак.\n";
    } else {
        for (int i = 0; i < num_dogs; i++) {
            dogs[i].show();
        }
    }
}