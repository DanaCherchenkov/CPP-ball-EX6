#include "doctest.h"
#include <vector>
#include <stdexcept>
#include <string>

#include "Team.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include "Schedule.hpp"

using namespace std;
using namespace ball;

TEST_CASE("Good test for built team"){
    Team team1 = Team();
    Team team2 = Team();
    CHECK_NOTHROW(team1.set_name_team("Maccabi"));
    CHECK_NOTHROW(team2.set_name_team("Maccabi-Haifa"));
    CHECK_NOTHROW(team1.set_uniqueness(1));
    CHECK_NOTHROW(team2.set_uniqueness(0.2));

    Game new_game = Game();
    new_game.set_home_team(&team1);
    new_game.set_out_team(&team2);
    
    CHECK(new_game.get_home_team().get_name_team() == "Maccabi");
    CHECK(new_game.get_out_team().get_name_team() == "Maccabi-Haifa");
    CHECK(new_game.get_home_team().get_points_obtained() == 0);
    CHECK_NOTHROW(new_game.get_home_team().set_points_obtained(50));
    CHECK_NOTHROW(new_game.get_out_team().set_points_obtained(60));
    CHECK_NOTHROW(new_game.get_home_team().update_points_obtained(50));
    CHECK(new_game.get_home_team().get_points_obtained() > 0);
    CHECK(new_game.get_out_team().get_points_obtained() < 100);
    CHECK(new_game.get_home_team().get_points_obtained() == 100);

    if(new_game.get_home_team().get_points_obtained() > new_game.get_out_team().get_points_obtained()){
        new_game.set_winner_name(new_game.get_home_team().get_name_team());
    }
    else{
        new_game.set_winner_name(new_game.get_out_team().get_name_team());
    }
    CHECK(new_game.get_winner_name() == team1.get_name_team());
}


TEST_CASE("Bad test for built team"){
    Team team1 = Team();
    Team team2 = Team();
    CHECK_NOTHROW(team1.set_name_team("Maccabi"));
    CHECK_NOTHROW(team2.set_name_team("Maccabi-Haifa"));
    CHECK_NOTHROW(team1.set_uniqueness(1));
    CHECK_NOTHROW(team2.set_uniqueness(0.2));

    Game new_game = Game();
    new_game.set_home_team(&team1);
    new_game.set_out_team(&team2);
    
    CHECK_NE(new_game.get_home_team().get_name_team(), "Maccabi-Haifa");
    CHECK_NE(new_game.get_out_team().get_name_team() , "Maccabi");
    CHECK(new_game.get_home_team().get_points_obtained() == 0);
    CHECK_NOTHROW(new_game.get_home_team().set_points_obtained(50));
    CHECK_NOTHROW(new_game.get_out_team().set_points_obtained(60));
    CHECK_NOTHROW(new_game.get_home_team().update_points_obtained(50));
    CHECK_FALSE(new_game.get_home_team().get_points_obtained() < 0);
    CHECK_FALSE(new_game.get_out_team().get_points_obtained() > 100);
    CHECK_FALSE(new_game.get_home_team().get_points_obtained() != 100);

    if(new_game.get_home_team().get_points_obtained() > new_game.get_out_team().get_points_obtained()){
        new_game.set_winner_name(new_game.get_home_team().get_name_team());
    }
    else{
        new_game.set_winner_name(new_game.get_out_team().get_name_team());
    }
    CHECK_NE(new_game.get_winner_name(), team2.get_name_team());
}

TEST_CASE("Good test for built leauge"){
    vector<Team*> new_team;
    new_team.push_back(new Team("Dana", 0.1));
    new_team.push_back(new Team("Dana1", 0.2));
    new_team.push_back(new Team("Dana2", 0.3));
    new_team.push_back(new Team("Dana3", 0.4));
    new_team.push_back(new Team("Dana4", 0.5));
    double j = 0.1;
    for(size_t i = 0; i < new_team.size(); i++){
        CHECK(new_team.at(i)->get_uniqueness() == j);
        j += 0.1;
    }
}