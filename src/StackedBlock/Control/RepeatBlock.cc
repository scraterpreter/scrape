#include <memory>
#include <string>
#include "StackedBlock/Control/RepeatBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/NestedBlock.h"

RepeatBlock::RepeatBlock(const std::shared_ptr<NestedBlock> t,
    const std::shared_ptr<StackOfBlocks> lb)
    : times(t),loopBody(lb){}

void RepeatBlock::exec() const
{
    for(int i=0; i<times->getDouble(); i++) loopBody->execAll();
}
