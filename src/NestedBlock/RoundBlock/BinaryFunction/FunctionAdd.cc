#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"

MultiType FunctionAdd::getValue() const
{
    return std::to_string(left->getDouble()+right->getDouble());
}
