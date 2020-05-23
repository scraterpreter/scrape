#include <memory>
#include "StackedBlock/StackedBlock.h"

class Variable;
class NestedBlock;

class ChangeVariable : public StackedBlock
{
public:
    ChangeVariable(std::shared_ptr<Variable> var,const std::shared_ptr<NestedBlock> val);
    void exec() const override;
private:
    std::shared_ptr<Variable> variable;
    const std::shared_ptr<NestedBlock> value;
};
