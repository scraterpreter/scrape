#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsJoin.h"

std::string OperatorsJoin::getValue() const
{
    return left->getValue() + right->getValue();
}

OperatorsJoin::OperatorsJoin(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> rb) : left(lb), right(rb) {}
