#include "Book.h"

Book::Book(int bookId, string bookName, string authorFirstName, string authorLastName) {
    this->bookId = bookId;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}

int Book::getbookId(){
    return this->bookId;
}

string Book::getbookName(){
    return this->bookName;
};

string Book::getAuthorFirstName(){
    return this->getAuthorFirstName();
}

string Book::getAuthorLastName(){
    return this->authorLastName;
}

time_t Book::getDueDate(){
    return this->dueDate;
}

void Book::setDueDate(time_t Date){
    this->dueDate = Date;
}

void Book::returnBook(){

}

void Book::borrowBook(Member *borrower, time_t dueDate){
    this->borrower = borrower;
    this->dueDate = dueDate;
}