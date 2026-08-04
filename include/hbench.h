#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <vector>
#include <algorithm>

#define HBENCH(func) h.time(func, #func)


class timer
{
    private:
        std::map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;
        std::map<std::string, std::vector<long long>> results;

    public:
        void start(const std::string&);
        void stop(const std::string&);
        void time(void (*func)(), const std::string& name);
        void report();
};
extern timer h;