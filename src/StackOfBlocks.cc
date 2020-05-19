#include <vector>
#include <StackedBlock/StackedBlock.h>
#include "StackOfBlocks.h"

void StackOfBlocks::execAll() const
{
    for(StackedBlock *b : blocks)
    {
        b->exec();
    }
}
StackOfBlocks::StackOfBlocks(const std::vector<StackedBlock*>& b)
    : blocks(b) {}
