#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class IfElseBlock : public StackedBlock
{
public:
    IfElseBlock(const std::shared_ptr<SharpBlock> cond,const std::shared_ptr<StackOfBlocks> ib,
        const std::shared_ptr<StackOfBlocks> eb);
    void exec() const override;
private:
    const std::shared_ptr<SharpBlock> condition;
    const std::shared_ptr<StackOfBlocks> ifBody;
    const std::shared_ptr<StackOfBlocks> elseBody;
};
