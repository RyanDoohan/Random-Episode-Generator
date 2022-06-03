#ifndef DISPLAYHELPERS
#define DISPLAYHELPERS

namespace fs = std::filesystem;

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

#endif