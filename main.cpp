#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include "hbench.h"



int main()
{
    HBENCH("test")
{    
    h.start("test");

    int x = 0;
    for (int i = 0; i < 100000; i++)
    {
        x += rand();
    }

    h.stop("test");
}
h.report();

    return 0;
}