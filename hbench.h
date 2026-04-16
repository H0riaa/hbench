#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <vector>
#include <algorithm>

#define HBENCH(name) \
for(int _i = 0; _i < 1000; _i++)


class timer
{
    private:
        std::map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;
        std::map<std::string, std::vector<long long>> results;

    public:
        void start(const std::string&);
        void stop(const std::string&);
        void report();
};
extern timer h;