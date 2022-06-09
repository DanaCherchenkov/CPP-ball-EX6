
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Team.hpp"

using namespace std;


namespace ball{
    class Leauge {
        private:
            vector<Team*>team_list;
        public:
            Leauge();
            Leauge(vector<Team*> other_team_list);
            void Leauge_random();
            void Leauge_half(vector<Team*> other_team_list);
            void initial_leauge();
    };
}
