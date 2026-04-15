#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include "hbench.h"



int main()
{
    h.start("test");
    
    int s = 0;

    for (int i = 0; i < 271000; i++)
    {
        s += i * i;
    }
    
    h.stop("test");
    h.report();

    return 0;
}