#pragma once
#include <iostream>

using namespace std;

namespace ball{
    class Team{
        private:
            string name_team;
            double uniqueness;
            int points_obtained;
            int all_wins;
            int all_losses;
            int curr_score_win;
            int winner_score;


        public:
            Team();
            Team(string new_name, double new_uniqueness);

            string get_name_team();
            void set_name_team(string new_name);

            double get_uniqueness();
            void set_uniqueness(double num);

            int get_points_obtained();
            void set_points_obtained(int num);

            int get_all_wins();
            void update_all_wins(int num);

            int get_all_losses();
            void update_all_losses(int num);

            void update_points_obtained(int num);

            int get_curr_score_win();
            void update_curr_score_win(int num);

            int get_winner_score();
            void set_winner_score(int num);
    };
}