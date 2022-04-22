#ifndef SHOWSLIST
#define SHOWSLIST

#include <iostream>
#include <vector>
#include "episode-list.h"

class ShowList {
    private:
        std::vector<EpisodeList> ShowLst;

    public:
        ShowList() {} // Default constructor with no arguments.
};

#endif