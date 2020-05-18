#include <string>
#include "NestedBlock/RoundBlock/Variable.h"

std::string Variable::getValue() const
{
    return val;
}

void Variable::setValue(std::string v)
{
    val = v;
}

Variable::Variable(std::string v) : val(v) {}
