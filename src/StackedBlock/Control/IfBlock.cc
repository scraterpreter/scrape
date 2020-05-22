#include <memory>
#include "StackedBlock/Control/IfBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

IfBlock::IfBlock(const std::shared_ptr<SharpBlock> cond,const std::shared_ptr<StackOfBlocks> ib)
    : condition(cond),ifBody(ib){}
void IfBlock::exec() const
{
    if(condition->getBool()) ifBody->execAll();
}
