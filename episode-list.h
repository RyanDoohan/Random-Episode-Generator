#ifndef EPISODELIST
#define EPISODELIST

#include <iostream>
#include <vector>

class EpisodeList {
    private:
        struct Episode {
            int episodeNumber, episodeSeason;
            std::string episodeName;
        };
        std::vector<Episode> EpisodeLst;
    public:
        EpisodeList(int episodeNum, int episodeSeas, std::string name) {
            Episode episode;
            episode.episodeNumber = episodeNum;
            episode.episodeSeason = episodeSeas;
            episode.episodeName = name;
            EpisodeLst.push_back(episode);
        }

        Episode getEpisode(int index) {
            Episode episode;

            episode.episodeName = EpisodeLst[index].episodeName;
            episode.episodeNumber = EpisodeLst[index].episodeNumber;
            episode.episodeSeason = EpisodeLst[index].episodeSeason;

            return episode;
        }

        std::string getEpisodeString(int index) {
            std::string result;
            
            result = std::to_string(EpisodeLst[index].episodeNumber) + " ";
            result += std::to_string(EpisodeLst[index].episodeSeason) + " ";
            result += EpisodeLst[index].episodeName;
            
            return result;
        }

        void displayAllEpisodes() {
            // for(Episode autoEpisode : EpisodeLst) {
            //     
            // }
            for(int i = 0; i < EpisodeLst.size(); i++) {
                std::cout << getEpisodeString(i) << std::endl;
            }
        }
};

#endif