#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"

MultiType FunctionDivide::getValue() const
{
    return left->getDouble()/right->getDouble();
}
