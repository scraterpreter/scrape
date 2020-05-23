#include <vector>
#include <memory>
#include <StackedBlock/StackedBlock.h>
#include "StackOfBlocks.h"

void StackOfBlocks::execAll() const
{
    for(std::shared_ptr<StackedBlock> b : *blocks)
    {
        b->exec();
    }
}
StackOfBlocks::StackOfBlocks(const std::shared_ptr<std::vector<std::shared_ptr<StackedBlock>>> b)
    : blocks(b) {}
