#include <iostream>
#include <string>
#include <map>
#include <chrono>


class timer
{
    private:
        std::map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;

    public:
        void start(const std::string&);
        void stop(const std::string&);
      
};
extern timer h;