#ifndef READCSV_H
#define READCSV_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


struct BookStruct {
    std::string bookId;
    std::string bookName;
    std::string pageCount;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
};

bool FindRecord(BookStruct &FindBook, std::string fileName, std::string searchTerm);

std::vector<BookStruct> GetAllBooks(std::string fileName);


#endif