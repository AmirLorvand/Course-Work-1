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
void issueBook(int memberId, int bookId) {
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
void returnBook(int memberId, int bookId);
void displayBorrowedBooks(int memberId);
void calcFine(int memberId);

int getstaffId();
void setstaffId(int staffId);

int getSalary();
void setSalary(int salary);