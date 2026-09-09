#include "header.h"
#include <iostream>
#include <iomanip>

using namespace std;

Detail::Detail() {
    name = "Невідома деталь";
    type = '-';
    count = 0;
    weight = 0;
}

Detail::Detail(string name, string type, int count, int weight) {
    this->name = name;
    this->type = type;
    this->count = count;
    this->weight = weight;
}

Detail:: Detail (const Detail &other){
    name = other.name;
    type = other.type;
    count = other.count;
    weight = other.weight;
}

Detail::~Detail() {
    cout << "Деструктор видалив деталь: " << name << endl;
}

void Detail::set_name(string n) {
    name = n;
}

void Detail::set_type (string t) {
    type = t;
}

void Detail::set_count(int c) {
   count = c;
}

void Detail::set_weight(int w) {
     weight = w;
}

string Detail::get_name() {
    return name;
}

string Detail::get_type() {
    
    return type; 
}

int Detail::get_count() {
    return count; 
}

int Detail::get_weight() {
    return weight;
}

int ukrLen(string text) {
    int count = 0;
    for (unsigned char c : text) {
        if (c > 127) count++; 
    }
    return count / 2; 
}

void Detail::show() {
    cout << "| " << left << setw(18 + ukrLen(name)) << name;
    cout << "| " << left << setw(8 + ukrLen(type)) << type;
    cout << "| " << left << setw(12) << count;
    cout << "| " << left << setw(15) << weight << " |" << endl;
}