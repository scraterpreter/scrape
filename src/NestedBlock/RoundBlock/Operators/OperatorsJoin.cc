#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsJoin.h"

MultiType OperatorsJoin::getValue() const
{
    return left->getString() + right->getString();
}

OperatorsJoin::OperatorsJoin(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> rb) : left(lb), right(rb) {}
