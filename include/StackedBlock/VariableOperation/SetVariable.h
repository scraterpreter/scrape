#include <memory>
#include "StackedBlock/StackedBlock.h"

class Variable;
class NestedBlock;

class SetVariable : public StackedBlock
{
public:
    SetVariable(std::shared_ptr<Variable> var,const std::shared_ptr<NestedBlock> val);
    void exec() const override;
private:
    std::shared_ptr<Variable> variable;
    const std::shared_ptr<NestedBlock> value;
};
