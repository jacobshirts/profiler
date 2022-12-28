#include <string>
#include <map>
#include "race.h"

using namespace std;

map<string,int> Human::update_stats(map<string, int> stats)
{
    map<string,int> player_stats = stats;

    player_stats["str"] += 1;
    player_stats["dex"] += 1; 
    player_stats["con"] += 1; 
    player_stats["int"] += 1;
    player_stats["wis"] += 1;
    player_stats["cha"] += 1;
    return player_stats;
}

map<string,int> Elf::update_stats(map<string, int> stats)
{
    map<string,int> player_stats = stats;

    player_stats["str"] += 0;
    player_stats["dex"] += 2; 
    player_stats["con"] += 0; 
    player_stats["int"] += 1;
    player_stats["wis"] += 0;
    player_stats["cha"] += 0;
    return player_stats;
}

map<string,int> Dwarf::update_stats(map<string, int> stats)
{
    map<string,int> player_stats = stats;

    player_stats["str"] += 0;
    player_stats["dex"] += 0; 
    player_stats["con"] += 2; 
    player_stats["int"] += 0;
    player_stats["wis"] += 1;
    player_stats["cha"] += 0;
    return player_stats;
}

map<string,int> Gnome::update_stats(map<string, int> stats)
{
    map<string,int> player_stats = stats;

    player_stats["str"] += 0;
    player_stats["dex"] += 0; 
    player_stats["con"] += 1; 
    player_stats["int"] += 2;
    player_stats["wis"] += 0;
    player_stats["cha"] += 0;
    return player_stats;
}

Race* race_factory(int race_num)
{
    Race *player;
    if (race_num == 0)
    {
        player = new Human();      
    }
    else if (race_num == 1)
    {
        player = new Elf();
    }
    else if (race_num == 2)
    {
        player = new Dwarf();
    }
    else if (race_num == 3)
    {
        player = new Gnome();
    }
    return player;
}

string race[] =
{
    "Human",
    "Elf",
    "Dwarf",
    "Gnome"
};

int get_race()
{
    int user_race = -1;
    while (user_race < 0 || user_race > 3)
    {
        cout << "Please select your race. The options are: (1) Human, (2) Elf, (3) Dwarf, (4) Gnome. ";
        cin >> user_race;
        user_race -= 1;
        if (user_race < 0 || user_race > 3)
            cout << "Input a valid number bozo. \n";
    }
    cout << "You selected: " << race[user_race] << endl;
    return user_race;
}