/*
    Additional_Functions.cpp
    Author: M00872834
    Created: 3 Jan 2024
    Updated: 4 Jan 2024
*/

#include "Additional_Functions.h"

namespace InputValidation {

    bool isChar(char ch) {
        return ((ch >= 'a' && ch <= 'z')
                || (ch >= 'A' && ch <= 'Z'));
    }

    bool EmailValidate(std::string email) {
        // Check the first character
        // is an alphabet or not
        if (!isChar(email[0])) {

            // If it's not an alphabet
            // email is not valid
            std::cout << "Wrong email please try again" << std::endl;
            return false;
        }

        // Variable to store position
        // of At and Dot
        int At = -1, Dot = -1;

        // Traverse over the email id
        // string to find position of
        // Dot and At
        for (int i = 0; i < email.length(); i++) {

            // If the character is '@'
            if (email[i] == '@') {

                //check if we have multiple @ in string
                if(At != -1){
                    std::cout << "Wrong email please try again" << std::endl;
                    return false;
                }

                At = i;
            }

            // If character is '.'
            else if (email[i] == '.') {

                //check if we have multiple Dot in string
                if(Dot != -1){
                    std::cout << "Wrong email please try again" << std::endl;
                    return false;
                }

                Dot = i;
            }
        }

        // If At or Dot is not present
        if (At == -1 || Dot == -1) {
            std::cout << "wrong email please try again" << std::endl;
            return false;
        }

        // If Dot is present before At
        if (At > Dot) {
            std::cout << "Wrong email please try again" << std::endl;
            return false;
        }

        // If Dot is at the end of email
        if (Dot >= (email.length() - 1)) {
            std::cout << "Wrong email please try again" << std::endl;
            return false;
        }

        return true;
    }

    bool NameValidate(std::string name) {

        for (char NameChar: name) {

            // check if its char or not
            if (!isChar(NameChar)) {
                std::cout << "Invalid Name Please try again" << std::endl;
                return false;
            }
        }
        return true;
    }

    bool ValidateYesNo(std::string UserInput){
        return (UserInput == "yes" || UserInput == "Yes"
        || UserInput == "YES" || UserInput == "y" || UserInput == "Y");
    }

    int ShowMenu(std::vector<std::string> Menu){
        std::cout << "Select the command number that you want to do" << std::endl;

        for (int MenuIndex=0; MenuIndex<Menu.size(); MenuIndex++){
            std::cout << MenuIndex+1 << " : " << Menu[MenuIndex] << std::endl;
        }
        std::cout << "Select: ";
        int SelectedCommand = getInputNum();

        if(SelectedCommand > Menu.size() || SelectedCommand <= 0){
            std::cout << "Invalid Command Please try again." << std::endl;
            return -1;
        }

        return SelectedCommand-1;

    }

    int getInputNum(){
        std::string Input;
        getline(std::cin, Input);

        for(int charNum=0; charNum<Input.size(); charNum++){
            if(Input[charNum] < '0' || Input[charNum] > '9'){
                std::cout << "Wrong input please try again" << std::endl;
                return -1;
            }
        }

        return stoi(Input);

    }
}

namespace BookFunctions {
    void showBook(Book book) {
        std::cout << "Book ID : " << book.getbookId() << std::endl <<
                  "Book Name : " << book.getbookName() << std::endl <<
                  "Book Author : " << book.getAuthorFirstName() << std::endl;

        if (book.getDueDate() != 0) {
            time_t Due = book.getDueDate();
            std::cout << "Due Date : " << ctime(&Due) << std::endl;
        }
    }

    void showBook(std::vector<Book> books) {
        for (Book book: books) {
            std::cout << "Book ID : " << book.getbookId() << "\t,\t" <<
                      "Book Name : " << book.getbookName() << "\t,\t" <<
                      "Book Author : " << book.getAuthorFirstName();

            if (book.getDueDate() != 0) {
                time_t Due = book.getDueDate();
                std::cout << "\t,\tDue Date : " << ctime(&Due);
            }

            std::cout << std::endl;
        }
    }

    void setFilePath() {

        std::cout << "Current path to file is : " << SharedData::FilePath << std::endl <<
                  "Would you like to change path? (yes/no)";

        std::string UserInput;
        getline(std::cin, UserInput);

        if (!InputValidation::ValidateYesNo(UserInput)) {
            std::cout << "Cancel Request" << std::endl;
            return;
        }

        while (true) {

            std::cout << "Please enter path to valid .CSV file : ";
            std::string path;
            getline(std::cin, path);

            // check if file path is csv file
            if(path.find(".csv") == std::string::npos){
                std::cout << "Input file path doesn't contain any .csv file Please try again." << std::endl;
                continue;
            }

            if (path == "exit")
                return;

            std::ifstream test(path);
            if (!test) {
                std::cout << "The file doesn't exist please enter a valid path (enter exit to exit to menu)."
                          << std::endl;
            } else {
                SharedData::FilePath = path;
                std::cout << "File successfully Added to program. " << std::endl;
                return;
            }
        }
    }

}