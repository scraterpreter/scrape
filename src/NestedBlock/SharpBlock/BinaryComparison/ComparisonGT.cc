#include <string>
#include <stdexcept>
#include <algorithm>
#include "NestedBlock/SharpBlock/BinaryComparison/ComparisonGT.h"

bool ComparisonGT::getBool() const
{
    try {
        return std::stod(left->getValue()) > std::stod(right->getValue());
    } catch (std::invalid_argument& e) {
        return left->getValue() > right->getValue();
    }
}
