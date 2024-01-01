#ifndef BOOK_H
#define BOOK_H

#include <ctime>
#include "Member.h"

class Book{
private:
    int bookId;
    string bookName;
    string authorFirstName;
    string authorLastName;
    string bookType;
    time_t dueDate;
    Member* borrower;

   
public:
    Book(int bookId, string bookName, string authorFirstName, string authorLastName);
    int getbookId();
    string getbookName();
    string getAuthorFirstName();
    string getAuthorLastName();
    time_t getDueDate();
    void setDueDate(time_t Date);
    void returnBook();
    void borrowBook(Member* borrower, time_t dueDate);
};

#endif
