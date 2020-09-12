#include <string>
#include <memory>
#include <cmath>
#include "NestedBlock/RoundBlock/Operators/OperatorsRound.h"

MultiType OperatorsRound::getValue() const
{
    return round(num->getDouble());
}

OperatorsRound::OperatorsRound(std::shared_ptr<NestedBlock> n) : num(n) {}
