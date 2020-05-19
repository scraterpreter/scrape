#include "StackedBlock/VariableOperation/SetVariable.h"
#include "NestedBlock/RoundBlock/Variable.h"
#include "NestedBlock/NestedBlock.h"

SetVariable::SetVariable(Variable& var,const NestedBlock& val)
    : variable(var),value(val) {}

void SetVariable::exec() const
{
    variable.setValue(value.getValue());
}
