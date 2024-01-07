#ifndef SHAREDDATA_H
#define SHAREDDATA_H

/*
    SharedData.h
    Author: M00872834
    Created: 2 Jan 2024
    Updated: 4 Jan 2024
*/

#include <vector>
#include "Member.h"
#include "Book.h"

namespace SharedData{
    extern std::vector<Member> Members;
    extern std::string FilePath;

    extern int GetMaxId();
}

#endif
