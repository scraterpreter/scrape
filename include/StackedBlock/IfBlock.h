#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class IfBlock : StackedBlock
{
public:
    IfBlock(const SharpBlock& cond,const StackOfBlocks& ib);
    void exec() const override;
private:
    const SharpBlock& condition;
    const StackOfBlocks& ifBody;
};
