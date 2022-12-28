#include <cstdlib>
#include <chrono>
#include "dice.h"

using namespace std;

int dice(int num_sides)
{
    auto now = chrono::system_clock::now();
    auto now_ms = chrono::time_point_cast<chrono::nanoseconds>(now);

    auto value = now_ms.time_since_epoch();
    long duration = value.count();

    srand(duration);
    int number = (rand() % num_sides)+1;
    return number;
}

