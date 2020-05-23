#include <memory>
#include "StackedBlock/Control/WaitUntilBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

WaitUntilBlock::WaitUntilBlock(const std::shared_ptr<SharpBlock> cond): condition(cond){}

void WaitUntilBlock::exec() const
{
    while (!condition->getBool()) {};
}
