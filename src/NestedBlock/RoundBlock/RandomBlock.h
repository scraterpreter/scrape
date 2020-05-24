#include <string>
#include <memory>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "NestedBlock/RoundBlock/RandomBlock.h"

std::string RandomBlock::getValue() const
{
    return std::to_string(rand() % (int)(upper->getDouble() - lower->getDouble() + 1) + (int)(lower->getDouble()));
}

RandomBlock::RandomBlock(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> ub) : lower(lb), upper(ub) {}
