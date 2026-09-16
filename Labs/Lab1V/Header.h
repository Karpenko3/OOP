#pragma once
#include <iostream>
#include <string>

using namespace std;


class DOG {
private:
    string name;
    float weight;
    int age;

public:
    DOG();
    DOG(string name, float weight, int age);
    DOG(const DOG &other);
    ~DOG();

    void set_name(string name);
    void set_weight(float weight);
    void set_age(int age);
    
    string get_name();
    float get_weight();
    int get_age();

    void show();
};


class MASTER {
private:
    string pib;
    const int club_id; 
    DOG* dogs;         
    int num_dogs;     
    static int count;  

public:
    MASTER();
    MASTER(string pib, int club_id);
    MASTER(const MASTER &other);
    ~MASTER();

    void set_pib(string pib);
    string get_pib();
    int get_club_id(); 
    
    static int get_count(); 

    void add_dog(const DOG &new_dog); 
    void show();
};