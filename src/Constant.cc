#include <string>
#include "Constant.h"

std::string Constant::getValue() const
{
    return val;
}
Constant::Constant(std::string v) : val(v) {}
