#include <string>
#include "NestedBlock/RoundBlock/Variable.h"

MultiType Variable::getValue() const
{
    return val;
}

void Variable::setValue(MultiType v)
{
    val = v;
}

Variable::Variable(std::string v) : val(v) {}
Variable::Variable() : val("dummy"){} // default constructor
