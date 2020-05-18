#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionAdd.h"

std::string FunctionAdd::getValue() const
{
    return std::to_string(left.getDouble()+right.getDouble());
}
