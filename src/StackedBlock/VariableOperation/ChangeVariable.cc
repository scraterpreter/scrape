#include <memory>
#include <string>
#include "StackedBlock/VariableOperation/ChangeVariable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/NestedBlock.h"

ChangeVariable::ChangeVariable(std::shared_ptr<Variable> var,
    const std::shared_ptr<NestedBlock> val)
    : variable(var),value(val) {}

void ChangeVariable::exec() const
{
    variable->setValue(std::to_string(variable->getDouble()+
        value->getDouble()));
}
