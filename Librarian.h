#ifndef UNTITLED1_LIBRARIAN_H
#define UNTITLED1_LIBRARIAN_H

#include "Person.h"
#include "Member.h"
#include "Book.h"
#include "Additional_Functions.h"
#include "SharedData.h"
#include "ReadCSV.h"

class Librarian : public Person{
private:
    int staffId;
    int salary;

public:
    Librarian(int staffId, std::string name, std::string address, std::string email, int salary);
    void addMember();
    void issueBook(int memberId, int bookId);
    void returnBook(int memberId, int bookId);
    void displayBorrowedBooks(int memberId);
    void calcFine(int memberId);

    int getstaffId();
    void setstaffId(int staffId);

    int getSalary();
    void setSalary(int salary);
};

#endif
