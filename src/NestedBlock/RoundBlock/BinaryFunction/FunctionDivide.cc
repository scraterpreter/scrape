#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"

MultiType FunctionDivide::getValue() const
{
    return std::to_string(left->getDouble()/right->getDouble());
}
