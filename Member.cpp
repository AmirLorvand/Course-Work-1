#include "Member.h"
#include "Book.h"

Member::Member(int memberId, string name, string address, string email){
    this -> memberId = memberId;
    this -> setName(name);
    this -> setAddress(address);
    this -> setEmail(email);
}

int Member::getMemberId(){
    return this -> memberId;
}

vector<Book> Member::getBookBorrowed(){
    return this -> bookLoaned;
}


void Member::setBookBorrowed(Book book){
    this -> bookLoaned.push_back(book);
}