#include <memory>
#include "StackedBlock/VariableOperation/SetVariable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/NestedBlock.h"

SetVariable::SetVariable(std::shared_ptr<Variable> var,const std::shared_ptr<NestedBlock> val)
    : variable(var),value(val) {}

void SetVariable::exec() const
{
    variable->setValue(value->getValue());
}
