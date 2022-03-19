#include <iostream>

#include "episode-list.h"

int main() {
    EpisodeList test;

    test.inputEpisodes("theoffice");
    std::cout << test.getRandomEpisode();
    
    return 0;
}