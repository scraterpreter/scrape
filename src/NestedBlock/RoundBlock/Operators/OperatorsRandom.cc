#include <string>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include "NestedBlock/RoundBlock/Operators/OperatorsRandom.h"

MultiType OperatorsRandom::getValue() const
{
    return rand() % (int)(upper->getDouble() - lower->getDouble() + 1) + (int)(lower->getDouble());
}

OperatorsRandom::OperatorsRandom(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> ub) : lower(lb), upper(ub) {}
