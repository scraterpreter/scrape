#include "StackedBlock/StackedBlock.h"

class Variable;
class NestedBlock;

class SetVariable : public StackedBlock
{
public:
    SetVariable(Variable& var,const NestedBlock& val);
    void exec() const override;
private:
    Variable& variable;
    const NestedBlock& value;
};
