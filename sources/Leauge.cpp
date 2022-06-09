#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Leauge.hpp"

int const MAX_PARTICIPANTS = 20;

using namespace std;

namespace ball{
    Leauge::Leauge(){}

    //Receives from outside a given set of groups
    Leauge::Leauge(vector<Team*> other_team_list){
        if(other_team_list.size() > 20){
            throw invalid_argument("No more than 20 teams can be admitted to the league");
        }
        for(size_t i = 0; i < MAX_PARTICIPANTS ; i++){
            this->team_list.push_back(other_team_list.at(i));
        }
    }

    //Does not accept outside groups and produces 20 groups at random
    void Leauge::Leauge_random(){
        double rand_num = rand() % 1; //generate number between 0 and 1
        size_t select_name = 0;
        for(size_t i = 0; i < MAX_PARTICIPANTS; i++){
            this->team_list.push_back(new Team(to_string(select_name), rand_num));
            select_name++;
        }
    }

    //Combination of the previous two sections
    void Leauge::Leauge_half(vector<Team*> other_team_list){
        if(other_team_list.size() == MAX_PARTICIPANTS){
            throw invalid_argument("Need less than 20 groups to implement the function");
        }
        for(size_t i = 0; i < other_team_list.size(); i++){
            this->team_list.push_back(other_team_list.at(i));
        }
        size_t places_left = (MAX_PARTICIPANTS - other_team_list.size());
        double rand_num = rand() % 1; //generate number between 0 and 1
        size_t select_name = 0;
        while(this->team_list.size() != MAX_PARTICIPANTS){
            for(size_t i = 0; i < MAX_PARTICIPANTS; i++){
                this->team_list.push_back(new Team(to_string(select_name), rand_num));
                select_name++;
            }   
        }
    }
    
    void Leauge::initial_leauge(){
        Schedule* new_schedual = new Schedule(this->team_list);
        vector<Game*> all_games = new_schedual->built_schedule();
        for (unsigned int i = 0; i < all_games.size(); i++) {
            all_games.at(i)->start_game();
        }
    }
}
