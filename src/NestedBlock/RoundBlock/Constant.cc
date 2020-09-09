#include <string>
#include "NestedBlock/RoundBlock/Constant.h"

MultiType Constant::getValue() const
{
    return val;
}
Constant::Constant(std::string v) : val(v) {}
