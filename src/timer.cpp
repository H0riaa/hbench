#include "hbench.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

timer h;
void timer::start(const std::string &name)
{
    startTimes[name] = std::chrono::high_resolution_clock::now();
}

void timer::stop(const std::string &name)
{
    auto end = std::chrono::high_resolution_clock::now();
    auto start = startTimes.at(name);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    results[name].push_back(duration);
}

void timer::report()
{
    json j;
    for (auto &pair : results)
    {
        const std::string &name = pair.first;
        std::vector<long long> &v = pair.second;
        std::vector<long long> sorted = v;
        std::sort(sorted.begin(), sorted.end());

        if (v.empty())
        {
            continue;
        }
        if (v.size() == 1)
        {
            std::cout << '\n';
            std::cout << name << '\n' << '\n';
            std::cout << "TIME: " << v[0] << "us\n";
            j[name]["time"] = v[0];
            continue;
        }
        long long median;

        if (sorted.size() % 2 == 0)
        {
            median = (sorted[sorted.size() / 2 - 1] + sorted[sorted.size() / 2]) / 2;
        }
        else
        {
            median = sorted[sorted.size() / 2];
        }
        long long min = v[0];
        long long max = v[0];
        long long sum = 0;
        for (long long x : v)
        {
            if (x < min)
            {
                min = x;
            }
            if (x > max)
            {
                max = x;
            }
            sum += x;
        }
        double avg = (double)sum / v.size();

        std::cout << '\n';
        std::cout << name << '\n' << '\n';
        std::cout << "MIN: " << min << "us\n";
        std::cout << "MAX: " << max << "us\n";
        std::cout << "AVERAGE: " << avg << "us\n";
        std::cout << "MEDIAN: " << median << "us\n";

        j[name]["min"] = min;
        j[name]["max"] = max;
        j[name]["average"] = avg;
        j[name]["median"] = median;
    }

    std::ofstream output_file("results.json");
    output_file << j.dump(4);
}
