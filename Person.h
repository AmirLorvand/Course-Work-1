#ifndef PERSON_H
#define PERSON_H

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