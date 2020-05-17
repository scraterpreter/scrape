#include "NestedBlock/SharpBlock/BinaryLogical/BinaryLogical.h"

BinaryLogical::BinaryLogical(const SharpBlock& l,const SharpBlock& r) : left(l),right(r) {}

std::string BinaryLogical::getValue() const
{
    return std::to_string(getBool() ? 1 : 0);
}
