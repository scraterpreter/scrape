#include <string>
#include "NestedBlock/RoundBlock/Constant.h"

std::string Constant::getValue() const
{
    return val;
}
Constant::Constant(std::string v) : val(v) {}
