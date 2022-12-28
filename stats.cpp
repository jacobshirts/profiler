#include <list>
#include <iostream>
#include "dice.h"
#include "stats.h"


using namespace std;

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int roll_stat(int num_rolls, string stat_name)
{
    int stat = 0;
    for (int i=0;i<num_rolls; i++)
    {
        stat += dice(6);
    }
    cout << stat_name << ": " << stat << endl;
    return stat;
}

// purpose: rolls d6 num_rolls times and removes the lowest value 
// returns: the sum of the remaining values.
int roll_stat_4d6(int num_rolls, string stat_name)
{
    // creates a list called rolls and assigns a dice roll to each element.
    list<int> rolls;
    for (int i=0;i<num_rolls; i++)
    {
        rolls.push_front(dice(6));
    }
    
    // sorts list from least to greatest and eliminates the least value.
    rolls.sort();
    rolls.pop_front();

    // sums the remaining terms in the list and assigns the value to the variable sum.
    int sum = 0;
    list<int>::iterator it;
    for (it = rolls.begin(); it != rolls.end(); ++it)
        sum += *it;
    
    cout << stat_name << ": " << sum << endl;
    return sum;
}

void Stats::print_stats()
{
    map<string,int> stats = this->stats;
    map<string, int>::iterator it;
    for (it = stats.begin(); it != stats.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}

map<string, int> pick_stat_method(int (*func)(int, string), int num_dice)
{
    map<string, int> player_stats = 
    {
        {"str", 0},
        {"dex", 0},
        {"con", 0},
        {"int", 0},
        {"wis", 0},
        {"cha", 0}
    };

    player_stats["str"] = func(num_dice, "Str");
    player_stats["dex"] = func(num_dice, "Dex");
    player_stats["con"] = func(num_dice, "Con");
    player_stats["int"] = func(num_dice, "Int");
    player_stats["wis"] = func(num_dice, "Wis");
    player_stats["cha"] = func(num_dice, "Cha");

    return player_stats;
}

map<string, int> roll_stats(int roll_method)
{
    map<string, int> player_stats;

    if (roll_method == 1)
    {    
        player_stats = pick_stat_method(&roll_stat, 3);
    }
    if (roll_method == 2)
    {
        player_stats = pick_stat_method(&roll_stat_4d6, 4);
    }
    return player_stats;
}

void Stats::set_stats(map<string, int> value)
{
    this->stats = value;
}

map<string, int> Stats::get_stats()
{
    return this->stats;
}

void Stats::make_stats()
{
    int roll_method = 0; 
    while(roll_method != 2 && roll_method != 1)
    {
        cout << "would you like ot roll stats using (1) 3d6 or (2) 4d6? ";
        cin >> roll_method;
        if (roll_method != 2 && roll_method != 1)
        {
            cout << "Input 1 or 2 stupid. \n";
        }
    }
    this->stats = roll_stats(roll_method);
}

