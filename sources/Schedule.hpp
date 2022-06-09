#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "Leauge.hpp"
#include "Game.hpp"

namespace ball{
    class Schedule{
        private:
            vector<Team*> list_teams;
        public:
            Schedule(vector<Team*> other_list_teams);
            Schedule();
            ~Schedule();
            vector<Game*> built_schedule();
        };
}

