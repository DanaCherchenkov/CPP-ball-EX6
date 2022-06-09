#include <iostream>

using namespace std;

#include "Team.hpp"

namespace ball{
    
    //constructors
    Team::Team(){
        this->name_team = "";
        this->uniqueness = 0.0;
        this->points_obtained = 0;
        int all_wins = 0;
        int all_losses = 0;
        int curr_win = 0;
        int winner_core = 0;

    }

    Team::Team(string new_name, double new_uniqueness){
        if(new_name == " " || new_name == "\n" || new_name == "\t"){
            throw invalid_argument("The name is not valid");
        }
        if(new_uniqueness > 1 || new_uniqueness < 0){
            throw invalid_argument("Invalid uniqueness number");
        }
        this->name_team = new_name;
        this->uniqueness = new_uniqueness;
        this->points_obtained = 0;
    }

    Team::Team(){}

    string Team::get_name_team(){
        return this->name_team;
    }

    void Team::set_name_team(string new_name){
        this->name_team = new_name;
    }

    double Team::get_uniqueness(){
        return this->uniqueness;
    }

    void Team::set_uniqueness(double num){
        this->uniqueness = num;
    }

    int Team::get_points_obtained(){
        return this->points_obtained;
    }

    void Team::set_points_obtained(int num){
        this->points_obtained = num;
    }

    int Team::get_all_wins(){
        return this->all_wins;
    }

    void Team::update_all_wins(int num){
        this->all_wins += num;
    }

    int Team::get_all_losses(){
        return this->all_losses;
    }

    void Team::update_all_losses(int num){
        this->all_losses += num;
    }

    void Team::update_points_obtained(int num){
        this->points_obtained += num;
    }

    int Team::get_curr_score_win(){
        return this->curr_score_win;
    }

    void Team::update_curr_score_win(int num){
        this->curr_score_win += num;
    }

    int Team::get_winner_score(){
        return this->winner_score;
    }
    
    void Team::set_winner_score(int num){
        this->winner_score = num;
    }
}