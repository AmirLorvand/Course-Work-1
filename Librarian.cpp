#include "Librarian.h"

Librarian::Librarian(int staffId, string name, string address, string email, int salary){
    this -> staffId = staffId;
    this -> setName(name);
    this -> setAddress(address);
    this -> setEmail(email);
    this -> salary = salary;
}


void Librarian::addMember(){
    string name;
    string address;
    string email;
    int ID;
    cout << "name";
    getline(cin, name);
    cout << "address";
    getline(cin, address);
    cout << "email";
    getline(cin, email);
    cout << "id:";
    ID = SharedData::GetMaxId();

    Member newMember(ID, name, address, email);
    SharedData::Members.push_back(newMember);

    for (Member mem : SharedData::Members){
        cout << mem.getMemberId() << " " << mem.getName() << endl;
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