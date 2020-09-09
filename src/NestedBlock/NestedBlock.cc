#include "NestedBlock/NestedBlock.h"

double NestedBlock::getDouble()
{
    return getValue().getDouble();
}

std::string NestedBlock::getString()
{
    return getValue().getString();
}
