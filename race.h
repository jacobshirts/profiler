#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Race
{
    public:
        virtual map<string,int> update_stats(map<string, int> stats) = 0;
};

class Human: public Race
{
    public:
        map<string,int> update_stats(map<string, int> stats);
};

class Elf: public Race
{
    public:
        map<string,int> update_stats(map<string, int> stats);
};

class Dwarf: public Race
{
    public:
        map<string,int> update_stats(map<string, int> stats);
};

class Gnome: public Race
{
    public:
        map<string,int> update_stats(map<string, int> stats);
};

Race* race_factory(int race_num);

int get_race();

#endif