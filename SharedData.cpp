/*
    SharedData.cpp
    Author: M00872834
    Created: 2 Jan 2024
    Updated: 4 Jan 2024
*/

#include "SharedData.h"

namespace SharedData{
    std::vector<Member> Members;
    std::string FilePath = "/Users/amir/Desktop/Course Work 1/library_books.csv";

    int GetMaxId(){
        int maxid = 0;
        for (Member mem : Members)
            if(mem.getMemberId() > maxid)
                maxid = mem.getMemberId();

        return maxid;
    }
}