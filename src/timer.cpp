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

void timer::time(void (*func)(), const std::string& name)
{
    for(int i = 0; i < 1000; i++)
    {
        start(name);
        func();
        stop(name);
    }
}

void timer::report()
{
    for(auto& pair : results)
    {
        const std::string& name = pair.first;
        std::vector<long long>& v = pair.second;
        std::vector<long long> sorted = v;
        std::sort(sorted.begin(), sorted.end());
        long long median;
        if(v.empty())
        {
            continue;
        }
        if(sorted.size() % 2 == 0)
        {
            median = (sorted[sorted.size()/2 - 1] + sorted[sorted.size()/2]) / 2;
        }
        else
        {
            median = sorted[sorted.size() / 2];
        }

     
        
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
        std::cout << "MEDIAN: " << median << "us\n";
    }
}