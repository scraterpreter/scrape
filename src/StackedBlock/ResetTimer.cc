#include "StackedBlock/ResetTimer.h"
#include "GlobalTimer.h"

ResetTimer::ResetTimer(std::shared_ptr<GlobalTimer> gt)
    : globalTimer(gt) {}

void ResetTimer::exec() const
{
    globalTimer->reset();
}
