#include <string>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include "NestedBlock/RoundBlock/Operators/OperatorsRandom.h"

std::string OperatorsRandom::getValue() const
{
    return std::to_string(rand() % (int)(upper->getDouble() - lower->getDouble() + 1) + (int)(lower->getDouble()));
}

OperatorsRandom::OperatorsRandom(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> ub) : lower(lb), upper(ub) {}
