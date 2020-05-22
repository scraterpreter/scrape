#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"

std::string FunctionDivide::getValue() const
{
    return std::to_string(left->getDouble()/right->getDouble());
}
