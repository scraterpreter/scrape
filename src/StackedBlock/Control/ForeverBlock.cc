#include <memory>
#include "StackedBlock/Control/ForeverBlock.h"
#include "StackOfBlocks.h"

ForeverBlock::ForeverBlock(const std::shared_ptr<StackOfBlocks> lb)
    : loopBody(lb){}

void ForeverBlock::exec() const
{
    while(true) loopBody->execAll();
}
