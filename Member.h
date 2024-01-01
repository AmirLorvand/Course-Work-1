#ifndef MEMBER_H
#define MEMBER_H

#include <vector>
#include <iostream>
#include <string>
#include "Person.h"

class Book;

class Member: public Person{
private:
    int memberId;
    vector<Book> bookLoaned;

public:
    Member(int memberId, string name, string address, string email);
    int getMemberId();
    vector<Book> getBookBorrowed();
    void setBookBorrowed(Book book);

};

#endif
