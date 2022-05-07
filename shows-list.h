#ifndef SHOWSLIST
#define SHOWSLIST

#include <iostream>
#include <vector>
#include "episode-list.h"
#include "display-functions.h"

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

        insertNewShow(EpisodeList episList, std::string newShowName) {
            Show newShow;

            newShow.showName = newShowName;
            newShow.showEpisodes = episList;

            showLst.push_back(newShow);
        }
};

#endif