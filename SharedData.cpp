#include "SharedData.h"

namespace SharedData{
    std::vector<Member> Members;
    std::vector<Book> Books;
    std::string FilePath;

    int GetMaxId(){
        int maxid = 0;
        for (Member mem : Members)
            if(mem.getMemberId() > maxid)
                maxid = mem.getMemberId();

        return maxid;
    }
}