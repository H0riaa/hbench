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

    h.report();

    return 0;
}