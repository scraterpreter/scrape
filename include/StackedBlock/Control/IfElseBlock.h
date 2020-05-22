#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class IfElseBlock : public StackedBlock
{
public:
    IfElseBlock(const SharpBlock& cond,const StackOfBlocks& ib,
        const StackOfBlocks& eb);
    void exec() const override;
private:
    const SharpBlock& condition;
    const StackOfBlocks& ifBody;
    const StackOfBlocks& elseBody;
};
