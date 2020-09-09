#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"

MultiType FunctionMultiply::getValue() const
{
    return std::to_string(left->getDouble()*right->getDouble());
}
