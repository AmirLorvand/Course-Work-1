#ifndef BOOK_H
#define BOOK_H

#include <ctime>
#include "Member.h"

class Book{
private:
    int bookId;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    time_t dueDate;
    Member* borrower;

   
public:
    Book(int bookId, std::string bookName, std::string authorFirstName, std::string authorLastName);
    int getbookId();
    std::string getbookName();
    std::string getAuthorFirstName();
    std::string getAuthorLastName();
    time_t getDueDate();
    void setDueDate(time_t Date);
    void returnBook();
    void borrowBook(Member* borrower, time_t dueDate);
};

#endif
