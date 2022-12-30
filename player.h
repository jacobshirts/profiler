#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "stats.h"
#include "race.h"


using namespace std;

class Player
{
    public:
        string player_name;
        Stats stats;
        Race *player_race;
        Player();
        void init();
};

#endif