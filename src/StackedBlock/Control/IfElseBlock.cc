#include <memory>
#include "StackedBlock/Control/IfElseBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

IfElseBlock::IfElseBlock(const std::shared_ptr<SharpBlock> cond,
    const std::shared_ptr<StackOfBlocks> ib,const std::shared_ptr<StackOfBlocks> eb)
    : condition(cond),ifBody(ib),elseBody(eb){}
void IfElseBlock::exec() const
{
    if(condition->getBool()) ifBody->execAll();
    else elseBody->execAll();
}
