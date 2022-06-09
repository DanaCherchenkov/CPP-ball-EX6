
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

#include "Schedule.hpp"

namespace ball{      
    Schedule::Schedule(vector<Team*> other_list_games){
        this->list_teams = other_list_games;
    }

    Schedule::Schedule(){}

    vector<Game*> Schedule::built_schedule(){
        if(this->list_teams.empty()){
            throw invalid_argument("There is no teams in the leauge");
        }
        vector<Game*> curr_schedule;
        curr_schedule.clear();
        for(size_t i = 0; i < this->list_teams.size(); i++){
            for(size_t j = 1; j < this->list_teams.size(); j++){
                if(i != j){
                    curr_schedule.push_back(new Game(this->list_teams.at(i), this->list_teams.at(j)));
                }
                continue;
            }
        }
        return curr_schedule;
    }
}

