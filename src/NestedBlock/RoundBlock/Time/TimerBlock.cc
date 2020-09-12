#include "NestedBlock/RoundBlock/Time/TimerBlock.h"
#include "GlobalTimer.h"

MultiType TimerBlock::getValue() const
{
    return globalTimer->timeElapsedInSeconds();
}

TimerBlock::TimerBlock(std::shared_ptr<GlobalTimer> gt) : globalTimer(gt) {}
