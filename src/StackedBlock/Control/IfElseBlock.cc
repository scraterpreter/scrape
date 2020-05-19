#include "StackedBlock/Control/IfElseBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

IfElseBlock::IfElseBlock(const SharpBlock& cond,
    const StackOfBlocks& ib,const StackOfBlocks& eb)
    : condition(cond),ifBody(ib),elseBody(eb){}
void IfElseBlock::exec() const
{
    if(condition.getBool()) ifBody.execAll();
    else elseBody.execAll();
}
