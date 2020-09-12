#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"

MultiType FunctionAdd::getValue() const
{
    return left->getDouble()+right->getDouble();
}
