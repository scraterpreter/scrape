#include <string>
#include <stdexcept>
#include <algorithm>
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonE.h"
#include <memory>

bool ComparisonE::getBool() const
{
    return left->getValue()==right->getValue();
}
