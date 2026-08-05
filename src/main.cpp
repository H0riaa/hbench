#include "hbench.h"
#include <cstdlib>
#include <iostream>

void test()
{
    int x = 0;

    for (int i = 0; i < 100000; i++)
    {
        x += rand();
    }
}

void test2(int a)
{
    int x = 0;
    for (int i = 0; i < a; i++)
    {
        x++;
    }
}

void test3(int a, int b)
{
    int s = 0;
    for (int i = 0; i < b; i++)
    {
        s += a;
    }
}

int main()
{
    HBENCH(test);

    int y = 0;
    int g = 1000000;

    HSTART("manual")

    for (int j = 0; j < 10000; j++)
    {
        y += rand();
    }

    HSTOP("manual")

    HBENCH([&]() { test2(g); });

    HBENCH([&]() { test3(5, 10000); });

    {
        scope_timer t("scope");
        int q = 0;
        for (int i = 0; i < 10000; i++)
        {
            q += rand();
        }
    }

    h.report();

    return 0;
}