#ifndef PERSON_H
#define PERSON_H

/*
    Person.h
    Author: M00872834
    Created: 30 Dec 2023
    Updated: 4 Jan 2024
*/

#include <iostream>
#include <string>

class Person{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName();
    void setName(std::string Name);

    std::string getAddress();
    void setAddress(std::string Address);

    std::string getEmail();
    void setEmail(std::string Email);
    
};

#endif