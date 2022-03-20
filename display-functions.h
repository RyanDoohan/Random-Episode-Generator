#ifndef DISPLAYFUNCTIONS
#define DISPLAYFUNCTIONS

#include <iostream>
#include "episode-list.h"

void displayWelcomeMessage(std::string & inputFile) {
    std::cout << "Random Episode Generator:\n";
    std::cout << "Enter the name of the input file, this file must be in the same host directory!\n : ";
    std::getline(std::cin, inputFile);
}

EpisodeList inputEpisodeFile(std::string inputEpisodeFile) {
    EpisodeList episList;
    if(episList.inputEpisodes(inputEpisodeFile)) {
        return episList;
    }
    else {
        std::cout << "File is invalid!\n";
        return episList;
    }
}

void generateRandomEpisode(EpisodeList episList) {
    std::string stop;

    std::cout << episList.getRandomEpisode();

    std::cout << "\n\nWould you like another episode? (y/n): ";
    std::getline(std::cin, stop);
    while(stop == "y") {
        std::cout << episList.getRandomEpisode();

        std::cout << "\n\nWould you like another episode? (y/n): ";
        std::getline(std::cin, stop);
    }
}

#endif