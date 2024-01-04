/*
    Book.cpp
    Author: M00872834
    Created: 2 Jan 2024
    Updated: 4 Jan 2024
*/

#include "Book.h"

Book::Book(int bookId, std::string bookName, std::string authorFirstName, std::string authorLastName) {
    this->bookId = bookId;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}

int Book::getbookId(){
    return this->bookId;
}

std::string Book::getbookName(){
    return this->bookName;
};

std::string Book::getAuthorFirstName(){
    return this->getAuthorFirstName();
}

std::string Book::getAuthorLastName(){
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