#ifndef EPISODELIST
#define EPISODELIST

#include <iostream>
#include <fstream>
#include <vector>

struct Episode { // Holds the episodes season, number, and name.
            int episodeNumber, episodeSeason;
            std::string episodeName;
        };

class EpisodeList {
    private:
        int numEpisodes; // Number of episodes currently stored in the episode list.
        std::vector<Episode> EpisodeLst; // Vector of Episode structs. Holds all epidoes.
    public:
        EpisodeList() {} // Default constructor with no arguments.

        EpisodeList(int episodeSeas, int episodeNum, std::string name) { // Default constructor for adding first episode.
            Episode episode;
            episode.episodeNumber = episodeNum;
            episode.episodeSeason = episodeSeas;
            episode.episodeName = name;
            EpisodeLst.push_back(episode);
            numEpisodes = 1;
        }

        Episode getEpisode(int index) { // Return an episode at a given index in EpisodeLst.
            Episode episode;

            episode.episodeName = EpisodeLst[index].episodeName;
            episode.episodeNumber = EpisodeLst[index].episodeNumber;
            episode.episodeSeason = EpisodeLst[index].episodeSeason;

            return episode;
        }

        void addEpisode(Episode newEpisode) { // Push a new episode to EpisodeLst.
            EpisodeLst.push_back(newEpisode);
            numEpisodes++; // Increment number of episodes.
        }

        int getNumEpisodes() { // Get number of episodes.
            return numEpisodes;
        }

        std::string getEpisodeString(int index) { // Will return a single formatted episode string for output.
            std::string result;
            
            result = std::to_string(EpisodeLst[index].episodeSeason) + " ";
            result += std::to_string(EpisodeLst[index].episodeNumber) + " ";
            result += EpisodeLst[index].episodeName;
            
            return result;
        }

        void displayAllEpisodes() { // Iterate through the whole EpisodeLst vector and display all episodes.
            for(int i = 0; i < EpisodeLst.size(); i++) {
                std::cout << getEpisodeString(i) << std::endl;
            }
        }

        void displayEpisodeNames() { // Iterate through the whole EpisodeLst vector and display all episode names.
            for(Episode autoEpis : EpisodeLst) {
                std::cout << autoEpis.episodeName << std::endl;
            }
        }

        void displayEpisode(Episode epis) { // Display a single formatted episode string, given an episode.
            std::string output;

            output = std::to_string(epis.episodeSeason) + " ";
            output += std::to_string(epis.episodeNumber) + " ";
            output += epis.episodeName;

            std::cout << output << std::endl;
        }

        void inputEpisodes(std::string fileName) {  // Episode file parser that uses 's:' as a delimiter for splitting up seasons
            Episode epis;                           // each new episode is separated by a newline char. The parser will automatically look for this format
                                                    // every delimiter within the episode input file will indicate a new season.
            std::ifstream episodeFile;              // The file parser looks for files only within the same host directory.
            std::string fileLine;
            int episNum = 0, episSeas = 0;

            episodeFile.open(fileName + ".txt");
            if(episodeFile.is_open()) { // Verify the input file was opened succesfully.
                while(std::getline(episodeFile, fileLine)) {
                    if(fileLine == "s:") { // Check to see if fileLine contains the new season delimiter.
                        episSeas++;
                        episNum = 0; // Reset episode count.
                    }
                    else {
                        episNum++;
                        epis.episodeSeason = episSeas;
                        epis.episodeNumber = episNum;
                        epis.episodeName = fileLine;
                        addEpisode(epis); // Push new episode to EpisodeLst.
                    }
                }
            }
            else {
                std::cout << "Invalid file name!\n"; // Error handling for invalid file.
            }
        }
};

#endif