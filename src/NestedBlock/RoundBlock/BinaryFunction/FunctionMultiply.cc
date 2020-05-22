#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"

std::string FunctionMultiply::getValue() const
{
    return std::to_string(left->getDouble()*right->getDouble());
}
