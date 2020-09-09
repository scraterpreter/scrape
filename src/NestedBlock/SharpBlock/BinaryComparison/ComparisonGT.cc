#include <string>
#include <stdexcept>
#include <algorithm>
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonGT.h"

bool ComparisonGT::getBool() const
{
    return left->getValue() > right->getValue();
}
