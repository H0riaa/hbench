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
    results[name].push_back(duration);
}

void timer::report()
{
    for(auto& pair : results)
    {
        const std::string& name = pair.first;
        std::vector<long long>& v = pair.second;

        long long min = v[0];
        long long max = v[0];
        long long sum = 0;
        for(long long x : v)
        {
            if(x < min)
            {
                min = x;
            }
            if(x > max)
            {
                max = x;
            }
            sum += x;
        }

        double avg = (double)sum / v.size();

        std::cout << name << '\n';
        std::cout << "MIN: " << min << "us\n";
        std::cout << "MAX: " << max << "us\n";
        std::cout << "AVERAGE: " << avg << "us\n";
    }
}