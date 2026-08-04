#include <iostream>
#include <cstdlib>
#include "hbench.h"

void test()
{
    int x = 0;

    for (int i = 0; i < 100000; i++)
    {
        x += rand();
    }
}

int main()
{
    HBENCH(test);

    int y = 0;
    HSTART()
        for(int j = 0; j < 10000; j++)
        {
            y += rand();
        }
    HSTOP()

    h.report();

    return 0;
}