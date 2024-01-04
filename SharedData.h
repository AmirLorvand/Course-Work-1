#ifndef SHAREDDATA_H
#define SHAREDDATA_H

/*
    SharedData.h
    Author: M00872834
    Created: 2 Jan 2024
    Updated: 4 Jan 2024
*/

#include <vector>
#include "Book.h"
#include "Member.h"

namespace SharedData{
    extern std::vector<Member> Members;
    extern std::vector<Book> Books;
    extern std::string FilePath;

    extern int GetMaxId();
}

#endif
