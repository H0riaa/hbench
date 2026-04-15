#include "hbench.h"

timer h;
void timer::start(const std::string& name)
{
    startTimes[name] = std::chrono::high_resolution_clock::now();
}

void timer::stop(const std::string& name)
{
    auto end = std::chrono::high_resolution_clock::now();
    auto start = startTimes.at(name);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << name << " a durat: " << duration << " microsecunde\n";
}