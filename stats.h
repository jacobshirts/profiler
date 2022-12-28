#include <map>
#include <string>

using namespace std;


class Stats
{
    public:
        void make_stats();
        void set_stats(map<string, int>);
        void print_stats();
        map<string, int> get_stats();
    private:
        map<string, int> stats;
};
