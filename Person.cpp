#include <iostream>
#include "Person.h"

string Person::getName(){
    return this -> name;
}

void Person::setName(std::string Name) {
    this -> name = Name;
}

string Person::getAddress() {
    return this -> address;
}

void Person::setAddress(std::string Address) {
    this -> address = Address;
}

string Person::getEmail() {
    return this -> email;
}

void Person::setEmail(std::string Email) {
    this -> email = Email;
}