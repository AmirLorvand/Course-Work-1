#include "ReadCSV.h"

/*
 * to read list of the books from CSV file
 */
std::vector<BookStruct> GetAllBooks(std::string fileName){
    std::vector<BookStruct> allBooks;
    BookStruct Book;


    std::ifstream file(fileName);

    std::string temp;


    while(getline(file, Book.bookId, ',')){

        if(char(file.peek()) == '\"'){
            file.get();
            
            getline(file, temp, '\"');
            Book.bookName = temp;
            getline(file, temp, ',');
            Book.bookName += temp;
        }

        else
            getline(file, Book.bookName, ',');
        
        getline(file, Book.pageCount, ',');
        getline(file, Book.authorFirstName, ',');
        getline(file, Book.authorLastName, ',');
        getline(file, Book.bookType, '\n');

        allBooks.push_back(Book);
    }

    return allBooks;

}

bool FindRecord(BookStruct &FindBook, std::string fileName, std::string searchTerm){

    std::vector<BookStruct> all = GetAllBooks(fileName);

    for (BookStruct book : all){
        if(book.bookName == searchTerm || book.bookId == searchTerm) {
            FindBook = book;
            return true;
        }
    }

    return false;
}