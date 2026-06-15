
# Library Management System – C++ OOP Coursework

This project is a console-based **Library Management System** developed in **C++**. It demonstrates object-oriented programming principles such as classes, inheritance, encapsulation, modular design, input validation, file handling, and unit testing.

The system allows a librarian to manage members, issue books, return books, display borrowed books, and calculate overdue fines using book data loaded from a CSV file.

---

## Features

* Add new library members
* Issue books to members
* Return borrowed books
* Display books borrowed by a member
* Calculate overdue fines
* Read book records from a CSV file
* Validate user input such as names, emails, numbers, and menu options
* Unit testing using Catch2
* Build automation using a Makefile

---

## Technologies Used

* C++
* Object-Oriented Programming
* File handling with CSV data
* Catch2 testing framework
* Makefile

---

## Project Structure

```text
.
├── main.cpp
├── Person.h / Person.cpp
├── Member.h / Member.cpp
├── Librarian.h / Librarian.cpp
├── Book.h / Book.cpp
├── ReadCSV.h / ReadCSV.cpp
├── SharedData.h / SharedData.cpp
├── Additional_Functions.h / Additional_Functions.cpp
├── Test.cpp
├── catch.hpp
├── library_books.csv
├── Makefile
└── README.md
```

---

## Main Classes

### Person

Base class containing common personal information such as:

* name
* address
* email

### Member

Represents a library member and stores:

* member ID
* borrowed books

### Librarian

Represents the librarian/admin user and provides the main system operations:

* add member
* issue book
* return book
* display borrowed books
* calculate fine

### Book

Represents a book record, including:

* book ID
* book name
* author name
* due date
* borrower information

---

## How to Run

Compile the main program using the Makefile:

```bash
make main
```

Run the program:

```bash
./main
```

---

## How to Run Tests

Compile the test program:

```bash
make test
```

Run the tests:

```bash
./test
```

---

## Example Menu

When the program starts, the librarian can choose from options such as:

```text
1 : AddMember
2 : Issue a book to a member
3 : Return a book from a member
4 : Display the borrowed books of a member
5 : Calculate fine for a member
6 : Set file path
7 : Exit program
```

---

## What I Learned

Through this coursework project, I practised:

* Designing a C++ program using multiple classes
* Applying inheritance through a base `Person` class
* Managing data using vectors and objects
* Reading and searching CSV files
* Building a menu-driven console application
* Writing unit tests with Catch2
* Using a Makefile to compile a multi-file C++ project

---

## Future Improvements

Possible improvements include:

* Replacing hard-coded file paths with relative paths
* Improving the book return logic so returned books are removed from the member’s borrowed list
* Storing member data persistently in a file or database
* Adding a graphical user interface
* Improving error handling and validation
* Refactoring the project into separate `src` and `tests` folders

---

## Author

**Amir Lorvand**
