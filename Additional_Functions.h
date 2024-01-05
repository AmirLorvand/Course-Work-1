#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

/*
    Additional_Functions.h
    Author: M00872834
    Created: 3 Jan 2024
    Updated: 4 Jan 2024
*/

#include <iostream>
#include <string>
#include "Book.h"
#include "SharedData.h"
#include "ReadCSV.h"
/*
 * this namespace is for checking and validating user input for each input.
 */
 
namespace InputValidation{

    extern bool isChar(char ch);
    extern bool EmailValidate(std::string email);
    extern bool NameValidate(std::string name);
    extern bool ValidateYesNo(std::string UserInput);
    extern int ShowMenu(std::vector<std::string> Menu);
    extern int getInputNum();

}

namespace BookFunctions{
    extern void showBook(Book book);
    extern void showBook(std::vector<Book> books);
    extern void setFilePath();
}

#endif
