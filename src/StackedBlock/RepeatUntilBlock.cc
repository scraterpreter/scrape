#include "StackedBlock/IfBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

RepeatUntilBlock::RepeatUntilBlock(const SharpBlock& cond,
    const StackOfBlocks& lb)
    : condition(cond),loopBody(lb){}

void RepeatUntilBlock::exec() const
{
    while(!condition.getBool()) loopBody.execAll();
}
