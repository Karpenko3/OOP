#pragma once
#include <iostream>
#include <string>

using namespace std;


class Detail{
private:
    string name;   
    string type;   
    int count;     
    int weight; 
public:
    Detail();
    Detail(string n, string t, int c, int w);
    Detail(const Detail &other);
    ~Detail();
    void show();

    void set_name(string n);
    void set_type(string t);
    void set_count(int c);
    void set_weight(int w);

    string get_name();
    string get_type();
    int get_count();
    int get_weight();
};
