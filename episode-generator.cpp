#include <iostream>

#include "episode-list.h"

int main() {
    EpisodeList test(1, 1, "Pilot");
    Episode tes;
    tes.episodeName = "Work";
    tes.episodeNumber = 2;
    tes.episodeSeason = 1;
    test.addEpisode(tes);
    test.displayAllEpisodes();


    return 0;
}