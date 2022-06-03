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

        void displayShowsByName() { // Function to display all shows added to the showLst vector by their respective name.
            std::cout << "\n\nAll currently imported shows:\n";
            for(int i = 0; i < showLst.size(); i++) {
                std::cout << i + 1 << ".) " << showLst[i].showName << std::endl;
            }
        }

        void insertNewShow(EpisodeList episList, std::string newShowName) { // Inserts a new show to the showLst vector.
            Show newShow;

            newShow.showName = newShowName;
            newShow.showEpisodes = episList;

            showLst.push_back(newShow);
        }

        EpisodeList searchShowList(std::string showName) {  // Find a show by showName string,
                                                            // Returns the EpisodeList object which can be referenced for other computation.
            EpisodeList episList;

            for(int i = 0; i < showLst.size(); i++) {
                if(showLst[i].showName == showName) {
                    return showLst[i].showEpisodes;
                }
            }
            std::cout << "\n*Error: Episode name entered was not found in the list of episodes.";
            return episList;
        }

        int getNumberOfShows() { // Return the number of shows currently added to the showLst vector.
            return showLst.size();
        }
};

#endif