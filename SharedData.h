#ifndef SHAREDDATA_H
#define SHAREDDATA_H

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
