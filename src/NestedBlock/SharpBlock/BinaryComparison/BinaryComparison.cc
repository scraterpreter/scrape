#include <string>
#include "NestedBlock/SharpBlock/BinaryComparison/BinaryComparison.h"

BinaryComparison::BinaryComparison(const NestedBlock& l,const NestedBlock& r) : left(l),right(r) {}

std::string BinaryComparison::getValue() const
{
    return std::to_string(getBool() ? 1 : 0);
}
