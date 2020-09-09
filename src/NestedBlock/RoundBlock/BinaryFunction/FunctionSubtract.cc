#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"

MultiType FunctionSubtract::getValue() const
{
    return std::to_string(left->getDouble()-right->getDouble());
}
