#include "StackedBlock/Control/IfBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

IfBlock::IfBlock(const SharpBlock& cond,const StackOfBlocks& ib)
    : condition(cond),ifBody(ib){}
void IfBlock::exec() const
{
    if(condition.getBool()) ifBody.execAll();
}
