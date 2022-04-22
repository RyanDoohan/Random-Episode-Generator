#ifndef SHOWSLIST
#define SHOWSLIST

#include <iostream>
#include <vector>
#include "episode-list.h"

struct Show {
    std::string showName;
    EpisodeList showEpisodes;
};

class ShowList {
    private:
        std::vector<Show> showLst;

    public:
        ShowList() {} // Default constructor with no arguments.

        displayShowsByName() {
            for(int i = 0; i < showLst.size(); i++) {
                std::cout << showLst[i].showName;
            }
        }

        insertNewShow(std::string name) {
            Show newShow;
            newShow.showName = name;
        }
};

#endif