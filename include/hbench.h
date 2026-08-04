#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>


#define HBENCH(func) h.time(func, #func)
#define HSTART(name)                                                                               \
    for (int _hloop_i = 0; _hloop_i < 1000; _hloop_i++)                                            \
    {                                                                                              \
        h.start(name);
#define HSTOP(name)                                                                                \
    h.stop(name);                                                                                  \
    }

class timer
{
  private:
    std::map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;
    std::map<std::string, std::vector<long long>> results;

  public:
    void start(const std::string &name = "manual");
    void stop(const std::string &name = "manual");
    template <typename Func> void time(Func func, const std::string &name)
    {
        const int warmup = 100;
        for (int i = 0; i < warmup; i++)
        {
            func();
        }
        for (int i = 0; i < 1000; i++)
        {
            start(name);
            func();
            stop(name);
        }
    }
    void report();
};
extern timer h;