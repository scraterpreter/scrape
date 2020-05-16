#include <string>
#include "FunctionMultiply.h"

std::string FunctionMultiply::getValue() const
{
    return std::to_string(std::stod(left.getValue())*std::stod(right.getValue()));
}
