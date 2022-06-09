#pragma once
#include <iostream>
#include "Team.hpp"

using namespace std;

namespace ball{
    class Game{
        private:
            Team* home_team;
            Team* out_team;
            string winner_team;

        public:
            Game();
            Game(Team* new_home_team, Team* new_out_team);
            Team get_home_team();
            void set_home_team(Team* new_team);
            Team get_out_team();
            void set_out_team(Team* new_team);
            string get_winner_name();
            void set_winner_name(string new_team);
            void start_game();
            double check_average(int win_score, int loss_score);
            double check_standard_deviation(int average, int win_score, int loss_score);
    };
}