#include <memory>
#include "StackedBlock/Control/RepeatUntilBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

RepeatUntilBlock::RepeatUntilBlock(const std::shared_ptr<SharpBlock> cond,
    const std::shared_ptr<StackOfBlocks> lb)
    : condition(cond),loopBody(lb){}

void RepeatUntilBlock::exec() const
{
    while(!condition->getBool()) loopBody->execAll();
}
