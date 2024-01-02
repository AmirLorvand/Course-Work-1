#include "Member.h"
#include "Book.h"

Member::Member(int memberId, std::string name, std::string address, std::string email){
    this -> memberId = memberId;
    this -> setName(name);
    this -> setAddress(address);
    this -> setEmail(email);
}

int Member::getMemberId(){
    return this -> memberId;
}

std::vector<Book> Member::getBookBorrowed(){
    return this -> bookLoaned;
}


void Member::setBookBorrowed(Book book){
    this -> bookLoaned.push_back(book);
}