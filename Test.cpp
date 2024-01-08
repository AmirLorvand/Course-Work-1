#define CATCH_CONFIG_MAIN

/*
    Test.cpp
    Author: M00872834
    Created: 8 Jan 2024
    Updated: 8 Jan 2024
*/

#include "catch.hpp"
#include "Librarian.h"
#include "Book.h"
#include "Member.h"
#include "SharedData.h"
#include "ReadCSV.h"

TEST_CASE("Librarian class test", "[librarian]"){

    Librarian Admin(101, "Amir", "SW1", "Amir@gmail.com", 2200);

    REQUIRE(Admin.getstaffId() == 101);
    REQUIRE(Admin.getAddress() == "SW1");
    REQUIRE(Admin.getName() == "Amir");
    REQUIRE(Admin.getEmail() == "Amir@gmail.com");
    REQUIRE(Admin.getSalary() == 2200);

    SECTION("change staffID and salary check"){
        Admin.setSalary(100);
        Admin.setstaffId(10);

        REQUIRE(Admin.getstaffId() == 10);
        REQUIRE(Admin.getSalary() == 100);
    }
}

TEST_CASE("Member Functions test","[member]"){
    Member newMember(5, "Amir2", "SW2", "Amir2@gmail.com");

    REQUIRE(newMember.getMemberId() == 5);
    REQUIRE(newMember.getAddress() == "SW2");
    REQUIRE(newMember.getName() == "Amir2");
    REQUIRE(newMember.getEmail() == "Amir2@gmail.com");

    SECTION("Check Shared data add member"){
        SharedData::Members.push_back(newMember);

        REQUIRE(SharedData::Members[0].getMemberId() == 5);
        REQUIRE(SharedData::GetMaxId() == 5);

        //add new member

        Member TestMember(SharedData::GetMaxId() + 1, "Amir3", "SW3", "Amir3@gmail.com");

        SharedData::Members.push_back(TestMember);


        REQUIRE(SharedData::Members[1].getMemberId() == 6);
        REQUIRE(SharedData::GetMaxId() == 6);
        
    }
}

TEST_CASE("Read csv file and Book function", "[book]"){
    BookStruct FoundBook;

    SharedData::FilePath = "/Users/amir/Desktop/Course Work 1/library_books.csv";

    REQUIRE(FindRecord(FoundBook, SharedData::FilePath, "5") == true);
    REQUIRE(FoundBook.bookId == "5");
    REQUIRE(FoundBook.bookName == "Pharaohs, Fellahs and Explorers");

    Book foundBook(stoi(FoundBook.bookId), FoundBook.bookName, FoundBook.authorFirstName,
                           FoundBook.authorLastName);

    REQUIRE(foundBook.getDueDate() == 0);

    time_t now = time(0);

    foundBook.setDueDate(now);

    REQUIRE(foundBook.getDueDate() == now);

}

TEST_CASE("Additional function test", "[additional]"){
    REQUIRE_FALSE(InputValidation::isChar('9'));
    REQUIRE(InputValidation::isChar('a'));
    
    REQUIRE_FALSE(InputValidation::NameValidate("Amir9"));
    REQUIRE(InputValidation::NameValidate("Amir"));

    REQUIRE_FALSE(InputValidation::EmailValidate("amir@123"));
    REQUIRE_FALSE(InputValidation::EmailValidate("amir@@gamei.com"));
    REQUIRE(InputValidation::EmailValidate("Amir3@gmail.com"));

    REQUIRE_FALSE(InputValidation::ValidateYesNo("no"));
    REQUIRE(InputValidation::ValidateYesNo("yes"));
    REQUIRE(InputValidation::ValidateYesNo("Yes"));
    REQUIRE(InputValidation::ValidateYesNo("y"));
    REQUIRE(InputValidation::ValidateYesNo("Y"));
}