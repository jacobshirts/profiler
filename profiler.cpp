#include <iostream>
#include <string>
#include "dice.h"
#include "race.h"
#include "stats.h"

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

int main()
{
    Stats stats = Stats();
    string character_name = get_name();
    stats.make_stats();
    int race_num = get_race();
    Race *player_race = race_factory(race_num);
    stats.set_stats(player_race->update_stats(stats.get_stats()));
    stats.print_stats();
}

