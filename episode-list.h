#ifndef EPISODELIST
#define EPISODELIST

#include <iostream>
#include <vector>

struct Episode {
            int episodeNumber, episodeSeason;
            std::string episodeName;
        };

class EpisodeList {
    private:
        int numEpisodes;
        std::vector<Episode> EpisodeLst;
    public:
        EpisodeList(int episodeSeas, int episodeNum, std::string name) {
            Episode episode;
            episode.episodeNumber = episodeNum;
            episode.episodeSeason = episodeSeas;
            episode.episodeName = name;
            EpisodeLst.push_back(episode);
            numEpisodes = 1;
        }

        Episode getEpisode(int index) {
            Episode episode;

            episode.episodeName = EpisodeLst[index].episodeName;
            episode.episodeNumber = EpisodeLst[index].episodeNumber;
            episode.episodeSeason = EpisodeLst[index].episodeSeason;

            return episode;
        }

        void addEpisode(Episode newEpisode) {
            EpisodeLst.push_back(newEpisode);
            numEpisodes++;
        }

        int getNumEpisodes() {
            return numEpisodes;
        }

        std::string getEpisodeString(int index) {
            std::string result;
            
            result = std::to_string(EpisodeLst[index].episodeSeason) + " ";
            result += std::to_string(EpisodeLst[index].episodeNumber) + " ";
            result += EpisodeLst[index].episodeName;
            
            return result;
        }

        void displayAllEpisodes() {
            for(int i = 0; i < EpisodeLst.size(); i++) {
                std::cout << getEpisodeString(i) << std::endl;
            }
        }

        void displayEpisodeNames() {
            for(Episode autoEpis : EpisodeLst) {
                std::cout << autoEpis.episodeName << std::endl;
            }
        }
};

#endif