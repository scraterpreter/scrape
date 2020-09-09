#include <string>
#include <stdexcept>
#include <algorithm>
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonLT.h"

bool ComparisonLT::getBool() const
{
    return left->getValue() < right->getValue();
}
