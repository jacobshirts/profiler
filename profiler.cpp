#include <iostream>
#include <string>
#include <vector>
#include "dice.h"
#include "race.h"
#include "stats.h"
#include "player.h"

using namespace std;

vector<Player> make_players(int player_num)
{
    vector<Player> players;
    for(int i=0;i<player_num;i++)
    {
        Player player = Player();
        player.init();
        players.push_back(player);
    }

    return players;
}

int main()
{
    cout << "How many players do you want to make? ";
    int player_num;
    cin >> player_num;
    vector<Player> players = make_players(player_num);
    players[0].stats.print_stats();
}

