#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/JoinBlock.h"

std::string JoinBlock::getValue() const
{
    return left->getValue() + right->getValue();
}

JoinBlock::JoinBlock(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> rb) : left(lb), right(rb) {}
