#include <iostream>
#include "Game.hpp"
#include <cmath>

int const BONUS = 10;

using namespace std;

namespace ball{
    Game::Game(){}

    Game::Game(Team* new_home_team, Team* new_out_team){
        this->home_team = new_home_team;
        this->out_team = new_out_team;
    }

    Team Game::get_home_team(){
        return *this->home_team;
    }

    void Game::set_home_team(Team* new_team){
        this->home_team = new_team;
    }

    Team Game::get_out_team(){
        return *this->out_team;
    }

    void Game::set_out_team(Team* new_team){
        this->out_team = new_team;
    }

    string Game::get_winner_name(){
        return this->winner_team;
    }

    void Game::set_winner_name(string new_team){
        this->winner_team = new_team;
    }

    double Game::check_average(int win_score, int loss_score){
        double ans = (win_score + loss_score)/2;
    }

    double Game::check_standard_deviation(int average, int win_score, int loss_score){
        double counter1 = pow((win_score - average),2);
        double counter2 = pow((loss_score - average), 2);
        double up = counter1 + counter2;
        return sqrt(up);
    }

    void Game::start_game(){
        int rand_num_home_team = rand() % 100 + 55; //generate number between 55 and 100
        int rand_num_out_team = rand() % 100 + 50; //generate number between 50 and 100

        //After the initial raffle, up to 10 bonus points will be added to each team
        rand_num_home_team += BONUS;
        rand_num_out_team += BONUS;

        this->home_team->update_points_obtained(rand_num_home_team);
        this->out_team->update_points_obtained(rand_num_out_team);

        if(home_team->get_points_obtained() > out_team->get_points_obtained()){
            this->home_team->update_all_wins(1);
            this->out_team->update_all_losses(1);
            this->home_team->update_curr_score_win(1);
            if(this->home_team->get_curr_score_win() > this->home_team->get_winner_score()){
                this->home_team->set_winner_score(this->home_team->get_curr_score_win());
            }
            cout<<"The winner -> " << this->home_team->get_name_team() << endl;
        }else if(home_team->get_points_obtained() < out_team->get_points_obtained()){
            this->out_team->update_all_wins(1);
            this->home_team->update_all_losses(1);
            this->out_team->update_curr_score_win(1);
            if(this->out_team->get_curr_score_win() > this->out_team->get_winner_score()){
                this->out_team->set_winner_score(this->out_team->get_curr_score_win());
            }
            cout<<"The winner -> " << this->out_team->get_name_team() << endl;
        }else{
            /*
                (if(home_team->get_points_obtained() == out_team->get_points_obtained()))
                We will select the group with the lowest standard deviation
            */
                double home_ave = this->check_average(home_team->get_all_wins(), home_team->get_all_losses());
                double out_ave = this->check_average(out_team->get_all_wins(), out_team->get_all_losses());
                double home_SD = this->check_standard_deviation(home_ave, home_team->get_all_wins(), home_team->get_all_losses());
                double out_SD = this->check_standard_deviation(out_ave, out_team->get_all_wins(), out_team->get_all_losses());
                if(home_SD > out_SD){
                    this->winner_team = this->home_team->get_name_team();
                    cout<<"The winner -> " << this->winner_team << endl;
                }
                this->winner_team = this->out_team->get_name_team();
                cout<<"The winner -> " << this->winner_team << endl;
            }
        }
}