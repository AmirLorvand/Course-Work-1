#ifndef MEMBER_H
#define MEMBER_H

/*
    Member.h
    Author: M00872834
    Created: 1 Jan 2024
    Updated: 4 Jan 2024
*/

#include <vector>
#include <iostream>
#include <string>
#include "Person.h"

class Book;

class Member: public Person{
private:
    int memberId;
    std::vector<Book> bookLoaned;

public:
    Member(int memberId, std::string name, std::string address, std::string email);
    int getMemberId();
    std::vector<Book> getBookBorrowed();
    void setBookBorrowed(Book book);

};

#endif
