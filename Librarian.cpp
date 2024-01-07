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

            bool isFound = FindRecord(Book_searched, SharedData::FilePath, std::to_string(bookId));

            if(!isFound){
                std::cout << "Book not found please try again" << std::endl;
                return;
            }

            Book foundBook(stoi(Book_searched.bookId), Book_searched.bookName, Book_searched.authorFirstName,
                           Book_searched.authorLastName);

            std::cout << "Is this the Book that you want to assign to user " << member.getName() << " :(yes/no)" << std::endl;
            BookFunctions::showBook(foundBook);

            std::string UserInput;
            getline(std::cin, UserInput);

            if(!InputValidation::ValidateYesNo(UserInput)){
                std::cout << "Cancel Request" << std::endl;
                return;
            }

            //std::cout << "give number of day for dueDate: ";
            int day = 3; // InputValidation::getInputNum();

            if(day < 0){
                return;
            }

            time_t DueDate = time(0) + (day * SEC_IN_DAY);

            foundBook.borrowBook(&member, DueDate );

            member.setBookBorrowed(foundBook);


            std::cout << "Book has been assigned to user " << member.getName() << " :" << std::endl ;
            BookFunctions::showBook(foundBook);

            return;
        }
    }
    std::cout << "No member found" << std::endl;
    return;
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

                    time_t current_time = time(0);
                    time_t BookDueDate = member_book.getDueDate();

                    std::cout << "found book " << member_book.getbookName() << " in member books. DueDate: " <<
                        ctime(&BookDueDate) << " current Date: " << ctime(&current_time) << std::endl <<
                        "would you like to pay your Fine? (yes/no) :";

//                    member_book.returnBook();

                    std::string UserInput;
                    getline(std::cin, UserInput);

                    if(InputValidation::ValidateYesNo(UserInput)) {
                        calcFine(memberId);
                    }

                    std::cout << "Book " << member_book.getbookName() << " has been return." << std::endl;

                    return;
                }
            }
            std::cout << "Book not found in member list.";
            return;
        }
    }
    std::cout << "No member found" << std::endl;
    return;
}

/*
    to display borrowed books by a member
    @mebmerId ID of the member
*/
void Librarian::displayBorrowedBooks(int memberId) {
    for (Member member: SharedData::Members) {
        if (member.getMemberId() == memberId) {

            if(member.getBookBorrowed().size() == 0){
                std::cout << "User " << member.getName() << " has no book borrowed yet." << std::endl;
                return;
            }

            BookFunctions::showBook(member.getBookBorrowed());
        }
    }
}

/*
    to calculate the fine if a book is overdue
    @memberId the ID of the member
*/
void Librarian::calcFine(int memberId) {
    int Fine = 0;
    time_t now = time(0);

    for (Member member: SharedData::Members) {
        if (member.getMemberId() == memberId) {

            for (Book member_book: member.getBookBorrowed()) {

                BookFunctions::showBook(member_book);

                int CalFine = int(now - member_book.getDueDate()) / SEC_IN_DAY;

                if(CalFine > 0)
                    Fine += CalFine;
            }

            std::cout << "calculated fine for user " << member.getName() << " is :" << Fine << std::endl;

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