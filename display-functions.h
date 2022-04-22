#ifndef DISPLAYFUNCTIONS
#define DISPLAYFUNCTIONS

#include <iostream>
#include "episode-list.h"

bool ensureDisplayFirstRun = true, ensureEpisodesAdded = true;

void getEpisodeFile(std::string & inputFile) {
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

int displayChoiceMenu() {
    std::string userChoice;

    if(ensureDisplayFirstRun == true) {
        std::cout << "Welcome to the random episode generator!";
        ensureDisplayFirstRun = false;
    }

    std::cout << "\n\n1.) Import a new episode file.\n";
    std::cout << "2.) Display all episode entries with season & episode number.\n";
    std::cout << "3.) Display all episode name entries.\n";
    std::cout << "4.) Generate a random episode.\n";
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

void displayMainMenu() {
    EpisodeList episList;
    std::string inputFile, stop = "y";

    while(stop == "y") {
        int retVal = displayChoiceMenu();

        switch(retVal) {
            case 1: {
                getEpisodeFile(inputFile);
                episList = inputEpisodeFile(inputFile);
                ensureEpisodesAdded = false;
                break;
            }
            case 2: {
                if(ensureEpisodesAdded == false) {
                    episList.displayAllEpisodes();
                }
                else {
                    std::cout << "\n*Error: Must import an episode file first!";
                }
                break;
            }
            case 3: {
                if(ensureEpisodesAdded == false) {
                    episList.displayEpisodeNames();
                }
                else {
                    std::cout << "\n*Error: Must import an episode file first!";
                }
                break;
            }
            case 4: {
                if(ensureEpisodesAdded == false) {
                    generateRandomEpisode(episList);
                }
                else {
                    std::cout << "\n*Error: Must import an episode file first!";
                }
                break;
            }
            case 5: {
                stop = "n"; // Update the stop string to terminate.
                break;
            }
            default: {
                std::cout << "\n*Error: Invalid input has been entered. Please restart!";
            }
        }
    }
}

#endif