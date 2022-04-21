#include <iostream>

#include "episode-list.h"
#include "display-functions.h"

int main() {
    EpisodeList episList;
    std::string inputFile;
    int retVal;

    std::string stop = "y";

    while(stop == "y") {
    retVal = displayMenu();

    switch(retVal) {
        case 1: {
            generateRandomEpisode(episList);
            break;
        }
        case 2: {
            episList.displayAllEpisodes();
            break;
        }
        case 3: {
            episList.displayEpisodeNames();
            break;
        }
        case 4: {
            displayWelcomeMessage(inputFile);
            episList = inputEpisodeFile(inputFile);
            break;
        }
        case 5: {
            stop = "n";
        }
        default: {}
    }
    }
    
    return 0;
}