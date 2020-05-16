#include <string>
#include "FunctionSubtract.h"

std::string FunctionSubtract::getValue() const
{
    return std::to_string(std::stod(left.getValue())-std::stod(right.getValue()));
}
