#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class RepeatUntilBlock : StackedBlock
{
public:
    RepeatUntilBlock(const SharpBlock& cond,const StackOfBlocks& lb);
    void exec() const override;
private:
    const SharpBlock& condition;
    const StackOfBlocks& loopBody;
};
