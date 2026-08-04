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

void test2(int a)
{
    int x = 0;
    for(int i = 0; i < a; i++)
    {
        x++;
    }
}

void test3(int a, int b)
{
    int s = 0;
    for(int i = 0; i < b; i++)
    {
        s += a;
    }
}

int main()
{
    HBENCH(test);

    int y = 0;
    int z = 1000000;
    HSTART()
        for(int j = 0; j < 10000; j++)
        {
            y += rand();
        }
    HSTOP()

    HBENCH([&]()
    {
        test2(z);
    });

    HBENCH([&]()
{
    test3(5,10000);
});

    h.report();

    return 0;
}