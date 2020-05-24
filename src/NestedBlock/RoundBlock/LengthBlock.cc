#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/LengthBlock.h"

std::string LengthBlock::getValue() const
{
    return std::to_string(str->getValue().length());
}

LengthBlock::LengthBlock(std::shared_ptr<NestedBlock> s) : str(s) {}
