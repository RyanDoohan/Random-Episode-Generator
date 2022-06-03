#ifndef DISPLAYFUNCTIONS
#define DISPLAYFUNCTIONS

#include <iostream>
#include <filesystem>
#include "episode-list.h"
#include "shows-list.h"

namespace fs = std::filesystem;

bool ensureDisplayFirstRun = true;

void displayShowFiles() {
    std::string episodesFilePath = "episodeFiles/";

    std::cout << "\n\nCurrent files in the episodeFiles directory:\n";

    for(const auto & entry : fs::directory_iterator(episodesFilePath)) {
        std::string fileNameStr = entry.path().string();

        fileNameStr = fileNameStr.substr(fileNameStr.find("/") + 1, fileNameStr.length());
        
        std::cout << fileNameStr << std::endl;
    }
}

void getEpisodeFile(std::string & inputFile) {
    displayShowFiles();

    std::cout << "\n\nEnter the name of the input file, this file must be in the episodeFiles directory!\n : ";
    std::getline(std::cin, inputFile);
}

void getNewShowName(std::string & newShowName) {
    std::cout << "\n\nEnter the name of the new show you would like the add here: ";
    std::getline(std::cin, newShowName);
}

EpisodeList inputEpisodeFile(std::string inputEpisodeFile) {
    EpisodeList episList;
    if(episList.inputEpisodes(inputEpisodeFile)) {
        return episList;
    }
    else {
        std::cout << "\n*Error: File name entered is invalid!";
        return episList;
    }
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

int displayEpisodeChoiceMenu(std::string showName) {
    std::string userChoice;

    std::cout << "\n\n===== Episode Menu =====\n";
    std::cout << "Current show: " << "'" << showName << "'" << "\n\n";
    std::cout << "1.) Display all episode entries with season & episode number.\n";
    std::cout << "2.) Display all episode name entries.\n";
    std::cout << "3.) Generate a random episode.\n";
    std::cout << "4.) Return to show selection menu.\n\n";
    std::cout << "Enter choice: ";

    std::getline(std::cin, userChoice);

    return (int)userChoice[0] - 48;
}

void displayEpisodeMenu(EpisodeList episList, std::string showName) {
    ShowList allShows;
    std::string newShowName, inputFile, stop = "y";

    while(stop == "y") {
        int retVal = displayEpisodeChoiceMenu(showName);

        switch(retVal) {
            case 1: {
                episList.displayAllEpisodes();
                break;
            }
            case 2: {
                episList.displayEpisodeNames();
                break;
            }
            case 3: {
                generateRandomEpisode(episList);
                break;
            }
            case 4: {
                stop = "n"; // Update the stop string to terminate.
                break;
            }
            default: {
                std::cout << "\n*Error: Invalid input has been entered. Please restart!";
                stop = "n"; // Update the stop string to terminate.
                break;
            }
        }
    }
}

int displayShowChoiceMenu(ShowList showLst) {
    if(ensureDisplayFirstRun == true) {
        std::cout << "\n\nWelcome to the random episode generator!";
        ensureDisplayFirstRun = false;
    }

    std::string userChoice;

    if(showLst.getNumberOfShows() < 1) {
        std::cout << "\n\n1.) Add new show to the list.\n";
        std::cout << "2.) Exit.\n\n";
        std::cout << "Enter choice: ";
    }
    else {
        std::cout << "\n\n1.) Add new show to the list.\n";
        std::cout << "2.) Display all shows currently added to the list.\n";
        std::cout << "3.) Choose a show.\n";
        std::cout << "4.) Display all files currently in the episodeFiles directory.\n";
        std::cout << "5.) Exit.\n\n";
        std::cout << "Enter choice: ";
    }

    std::getline(std::cin, userChoice);

    int retVal = (int)userChoice[0] - 48;

    return retVal;
}

void displayShowMenu() {
    EpisodeList episList;
    ShowList allShows;
    std::string newShowName, inputFile, stop = "y";

    while(stop == "y") {
        int retVal = displayShowChoiceMenu(allShows);

        switch(retVal) {
            case 1: {
                getNewShowName(newShowName);
                getEpisodeFile(inputFile);
                episList = inputEpisodeFile(inputFile);

                if(episList.getNumEpisodes() > 0) {
                    allShows.insertNewShow(episList, newShowName);
                }
                break;
            }
            case 2: {
                allShows.displayShowsByName();
                break;
            }
            case 3: {
                allShows.displayShowsByName();
                
                std::cout << "\nEnter the name of the show you want here: ";
                std::getline(std::cin, newShowName);

                episList = allShows.searchShowList(newShowName);

                if(episList.getNumEpisodes() > 1) {
                    displayEpisodeMenu(episList, newShowName);
                }
                break;
            }
            case 4: {
                displayShowFiles();
                break;
            }
            case 5: {
                stop = "n"; // Update the stop string to terminate.
                break;
            }
            default: {
                std::cout << "\n*Error: Invalid input has been entered. Please restart!";
                stop = "n"; // Update the stop string to terminate.
                break;
            }
        }
    }
}

#endif