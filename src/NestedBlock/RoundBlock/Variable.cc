#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Variable.h"

std::string Variable::getValue() const
{
    return *val.get();
}

void Variable::setValue(std::string v)
{
    val = v;
}

Variable::Variable(std::string v) : val(v) {}
Variable::Variable(){} // default constructor
