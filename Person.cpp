/*
    Person.h
    Author: M00872834
    Created: 30 Dec 2023
    Updated: 4 Jan 2024
*/

#include <iostream>
#include "Person.h"

std::string Person::getName(){
    return this -> name;
}

void Person::setName(std::string Name) {
    this -> name = Name;
}

std::string Person::getAddress() {
    return this -> address;
}

void Person::setAddress(std::string Address) {
    this -> address = Address;
}

std::string Person::getEmail() {
    return this -> email;
}

void Person::setEmail(std::string Email) {
    this -> email = Email;
}