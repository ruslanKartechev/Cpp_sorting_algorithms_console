#pragma once
#include "Utils.h"
#include <cstdlib>
#include <time.h>

namespace Utils
{
    void InitUtils()
    {
        srand(time(0));
    }

    int GetRandRange(int min, int max)
    {
        return (rand() % (max - min + 1) + min);
    }
}
