#ifndef DISPLAYFUNCTIONS
#define DISPLAYFUNCTIONS

#include <iostream>
#include "episode-list.h"

bool firstRunFlag = true;

void displayWelcomeMessage(std::string & inputFile) {
    std::cout << "\n\nEnter the name of the input file, this file must be in the same host directory!\n : ";
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

int displayMenu() {
    std::string userChoice;

    if(firstRunFlag == true) {
        std::cout << "Welcome to the random episode generator!";
        firstRunFlag = false;
    }

    std::cout << "\n\n1.) Generate a random episode.\n";
    std::cout << "2.) Display all episode entries with season & episode number.\n";
    std::cout << "3.) Display all episode name entries.\n";
    std::cout << "4.) Import a new episode file.\n";
    std::cout << "5.) Exit.\n\n";
    std::cout << "Enter choice: ";

    std::getline(std::cin, userChoice);

    return (int)userChoice[0] - 48;
}

void generateRandomEpisode(EpisodeList episList) {
    std::string stop;

    std::cout << "\nRandom Episode: " + episList.getRandomEpisode();

    std::cout << "\n\nWould you like another episode? (y/n): ";
    std::getline(std::cin, stop);
    while(stop == "y") {
        std::cout << "\nRandom Episode: " + episList.getRandomEpisode();

        std::cout << "\n\nWould you like another episode? (y/n): ";
        std::getline(std::cin, stop);
    }
}

#endif