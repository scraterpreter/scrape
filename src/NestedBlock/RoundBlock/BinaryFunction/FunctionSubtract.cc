#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionSubtract.h"

MultiType FunctionSubtract::getValue() const
{
    return left->getDouble()-right->getDouble();
}
