#include <iostream>
#include "Member.h"
#include "Librarian.h"

int main() {

    Librarian Admin(101, "Amir", "SW1", "Amir@gmail.com", 2200);

    std::cout << "Welcom " << Admin.getName() << std::endl;

    std::vector<std::string> Commands = {"AddMember", "Issue a book to a member", "Return a book from a member",
                                         "Display the borrowed books of a member", "Calculate fine for a member",
                                         "Set file path", "Exit program"};

    while (true) {
        int SelectCommand = InputValidation::ShowMenu(Commands);

        switch (SelectCommand) {
            case 0: { // addmember
                Admin.addMember();
                break;
            }

            case 1: { // Issue a book to member
                std::cout << "Please enter the ID of member: ";
                int MemberId = InputValidation::getInputNum();

                if (MemberId != -1) {
                    std::cout << "Please enter the ID of desire Book: ";
                    int BookId = InputValidation::getInputNum();

                    if (BookId != -1) {
                        Admin.issueBook(MemberId, BookId);
                    }
                }
                break;
            }

            case 2: { // return book
                std::cout << "Please enter the id of Member: ";
                int MemberId = InputValidation::getInputNum();

                if (MemberId != -1) {
                    std::cout << "Please enter the id of desire Book: ";
                    int BookId = InputValidation::getInputNum();

                    if (BookId != -1) {
                        Admin.returnBook(MemberId, BookId);
                    }
                }
                break;
            }

            case 3: { // display borrowed books
                std::cout << "Please enter the id of Member: ";
                int MemberId = InputValidation::getInputNum();

                if(MemberId != -1){
                    Admin.displayBorrowedBooks(MemberId);
                }
                break;
            }

            case 4:{ // calculate fine
                std::cout << "Please enter the id of Member: ";
                int MemberId = InputValidation::getInputNum();

                if(MemberId != -1){
                    Admin.calcFine(MemberId);
                }
                break;
            }

            case 5:{ // give new book.csv file
                BookFunctions::setFilePath();
                break;
            }

            case 6:{
                return 0;
            }

            default:
                break;
        }

    }

}