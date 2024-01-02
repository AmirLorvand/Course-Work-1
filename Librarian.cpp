#include "Librarian.h"

Librarian::Librarian(int staffId, std::string name, std::string address, std::string email, int salary){
    this -> staffId = staffId;
    this -> setName(name);
    this -> setAddress(address);
    this -> setEmail(email);
    this -> salary = salary;
}


void Librarian::addMember(){
    std::string name;
    std::string address;
    std::string email;
    int ID;
    std::cout << "name";
    std::getline(std::cin, name);
    std::cout << "address";
    std::getline(std::cin, address);
    std::cout << "email";
    std::getline(std::cin, email);
    std::cout << "id:";
    ID = SharedData::GetMaxId();

    Member newMember(ID, name, address, email);
    SharedData::Members.push_back(newMember);

    for (Member mem : SharedData::Members){
        std::cout << mem.getMemberId() << " " << mem.getName() << std::endl;
    }

}
void issueBook(int memberId, int bookId);
void returnBook(int memberId, int bookId);
void displayBorrowedBooks(int memberId);
void calcFine(int memberId);

int getstaffId();
void setstaffId(int staffId);

int getSalary();
void setSalary(int salary);