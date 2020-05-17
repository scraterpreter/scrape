#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/FunctionDivide.h"

std::string FunctionDivide::getValue() const
{
    return std::to_string(std::stod(left.getValue())/std::stod(right.getValue()));
}
