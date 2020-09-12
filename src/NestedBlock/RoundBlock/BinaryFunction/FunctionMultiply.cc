#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionMultiply.h"

MultiType FunctionMultiply::getValue() const
{
    return left->getDouble()*right->getDouble();
}
