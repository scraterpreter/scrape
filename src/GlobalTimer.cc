#include "GlobalTimer.h"

GlobalTimer::GlobalTimer()
{
    reset();
}

void GlobalTimer::reset()
{
    time=clock();
}

double GlobalTimer::timeElapsedInSeconds() const
{
    return ((double)(clock()-time))/CLOCKS_PER_SEC;
}
