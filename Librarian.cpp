/*
    Librarian.cpp
    Author: M00872834
    Created: 30 Dec 2023
    Updated: 4 Jan 2024
*/

#include "Librarian.h"

// number of seconds in a day (24 hour)
#define SEC_IN_DAY 86400

/*
 * constructor of class Librarian
 */
 
Librarian::Librarian(int staffId, std::string name, std::string address, std::string email, int salary){
    this -> staffId = staffId;
    this -> setName(name);
    this -> setAddress(address);
    this -> setEmail(email);
    this -> salary = salary;
}

/*
 * to add a new member to the library
 */
void Librarian::addMember(){
    std::string name;
    std::string address;
    std::string email;

    std::cout << "enter new member fullname : ";
    getline(std::cin, name);

    if(!InputValidation::NameValidate(name))
        return;

    std::cout << "enter new member address : ";
    getline(std::cin, address);

    std::cout << "enter new member email address : ";
    getline(std::cin, email);

    if(!InputValidation::EmailValidate(email))
        return;

    int ID = SharedData::GetMaxId() + 1;

    std::cout <<"Do you want to add User " << name << " With Id of " << ID << " ? (yes or no)" << std::endl;

    std::string UserInput;
    getline(std::cin, UserInput);

    if(!InputValidation::ValidateYesNo(UserInput)){
        std::cout << "cancel Request" << std::endl;
        return;
    }

    Member newMember(ID, name, address, email);
    SharedData::Members.push_back(newMember);


    std::cout << "User " << name << " With Id of " << ID << " has Been added." << std::endl;

}

/*
   funtion to issue a book to a member
   @bookId the ID of the book
   @memberId the ID of the member 
*/
void Librarian::issueBook(int memberId, int bookId) {
    for (Member &member: SharedData::Members) {
        if (member.getMemberId() == memberId) {
            BookStruct Book_searched;
            FindRecord(Book_searched, SharedData::FilePath, std::to_string(bookId));
            // create book for

            std::cout << Book_searched.bookName << Book_searched.bookId;

            Book foundBook(stoi(Book_searched.bookId), Book_searched.bookName, Book_searched.authorFirstName,
                           Book_searched.authorLastName);

            std::cout << "give num of day: ";
            int day = 3;
            std::cin >> day;

            time_t now = time(0);

            foundBook.borrowBook(&member, now + (day * SEC_IN_DAY));

            member.setBookBorrowed(foundBook);

            std::cout << "Done";

            return;
        }
    }
}

/*
    to return a book to the library
    @memberId ID of the member
    @bookId ID of the book
*/
void Librarian::returnBook(int memberId, int bookId) {
    
    for (Member mem: SharedData::Members) {
        if (mem.getMemberId() == memberId) {
            for (Book member_book: mem.getBookBorrowed()) {
                if (member_book.getbookId() == bookId) {
                    member_book.returnBook();
                    std::cout << "found book";
                }
            }
        }
    }
}
/*
    to display borrowed books by a member
    @mebmerId ID of the member
*/
void Librarian::displayBorrowedBooks(int memberId) {
    for (Member member: SharedData::Members) {
        if (member.getMemberId() == memberId) {

            for (Book member_book: member.getBookBorrowed()) {
                time_t duo = member_book.getDueDate();
                std::cout << member_book.getbookId() << " , " << member_book.getbookName() << " , " << ctime(&duo) << std::endl;
            }
        }
    }
}

/*
    to calculate the fine if a book is overdue
    @memberId the ID of the member
*/
void Librarian::calcFine(int memberId) {
    int Fine = 0;
    for (Member member: SharedData::Members) {
        if (member.getMemberId() == memberId) {

            for (Book member_book: member.getBookBorrowed()) {
                time_t due = member_book.getDueDate();
                std::cout << "Due date of book " << member_book.getbookName() << " is : " << ctime(&due) << std::endl;
                Fine += int(time(0) - member_book.getDueDate()) / SEC_IN_DAY;
            }

            std::cout << "calculated fine = " << Fine << std::endl;

        }
    }
}

/*
    staffId getter
    @return staff ID
*/
int Librarian::getstaffId() {
    return this->getstaffId();
}

/*
    staffId setter
    @staffId the ID of the staff
*/
void Librarian::setstaffId(int staffId) {
    this->staffId = staffId;
}

/*
    salary getter
    @return salary
*/
int Librarian::getSalary() {
    return this->salary;
}

/*
    salary setter
    @salary the salary of the staff
*/
void Librarian::setSalary(int salary) {
    this->salary = salary;
}