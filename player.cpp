#include <string>
#include "player.h"

using namespace std;

string get_name()
{
    string character_name;
    string input = "n";
    while(input == "n")
    {
        cout << "\nEnter character name: ";
        cin >> character_name;
        cout << "You entered: " << character_name << "\nAre you sure about this name? (y/n) ";
        cin >> input;
    }
    return character_name;
    
}

Player::Player()
{
    this->stats = Stats();
    
}

void Player::init()
{
    this->player_name = get_name();
    this->stats.make_stats();

    // Creating a race object.
    int race_num = get_race();
    this->player_race = race_factory(race_num);

    this->stats.set_stats(this->player_race->update_stats(this->stats.get_stats()));
};