/*
    SharedData.cpp
    Author: Amir Lorvand
    Created: 2 Jan 2024
    Updated: 4 Jan 2024
*/

#include "SharedData.h"

namespace SharedData{
    std::vector<Member> Members;
    std::string FilePath = "library_books.csv";

    int GetMaxId(){
        int maxid = 0;
        for (Member mem : Members)
            if(mem.getMemberId() > maxid)
                maxid = mem.getMemberId();

        return maxid;
    }
}
