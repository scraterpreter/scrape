#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class IfElseBlock : public StackedBlock
{
public:
    IfElseBlock(const std::shared_ptr<SharpBlock> cond,const std::shared_ptr<StackOfBlocks> ib,
        const shared_ptr<StackOfBlocks> eb);
    void exec() const override;
private:
    const shared_ptr<SharpBlock> condition;
    const shared_ptr<StackOfBlocks> ifBody;
    const shared_ptr<StackOfBlocks> elseBody;
};
