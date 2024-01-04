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
            std::cout << "wrong email please try again" << std::endl;
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
                    std::cout << "wrong email please try again" << std::endl;
                    return false;
                }

                At = i;
            }

            // If character is '.'
            else if (email[i] == '.') {

                //check if we have multiple Dot in string
                if(Dot != -1){
                    std::cout << "wrong email please try again" << std::endl;
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
            std::cout << "wrong email please try again" << std::endl;
            return false;
        }

        // If Dot is at the end of email
        if (Dot >= (email.length() - 1)) {
            std::cout << "wrong email please try again" << std::endl;
            return false;
        }

        return true;
    }

    bool NameValidate(std::string name) {

        for (char NameChar: name) {

            // check if its char or not
            if (!isChar(NameChar)) {
                std::cout << "Invalid Name Please try again";
                return false;
            }
        }
        return true;
    }

    bool ValidateYesNo(std::string UserInput){
        return (UserInput == "yes" || UserInput == "Yes"
        || UserInput == "YES" || UserInput == "y" || UserInput == "Y");
    }
}