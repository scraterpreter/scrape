#include "StackedBlock/StackedBlock.h"
#include <memory>

class NestedBlock;
class Variable;

class AskAndWait : public StackedBlock
{
public:
    AskAndWait(std::shared_ptr<NestedBlock> q,
        std::shared_ptr<Variable> av);
    void exec() const override;
private:
    std::shared_ptr<NestedBlock> question;
    std::shared_ptr<Variable> answerVariable;
};
