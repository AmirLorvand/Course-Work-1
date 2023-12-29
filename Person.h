#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string name;
    string address;
    string email;

public:
    string getName();
    void setName(string Name);

    string getAddress();
    void setAddress(string Address);

    string getEmail();
    void setEmail(string Email);
    
};

#endifs