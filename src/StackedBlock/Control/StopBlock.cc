#include "StackedBlock/Control/StopBlock.h"
#include "NestedBlock/RoundBlock/Constant.h"

StopBlock::StopBlock(std::shared_ptr<Constant> opt) : option(opt) {}

void StopBlock::exec() const
{
    if(option->getValue()=="all" || option->getValue()=="this script")
    {
        throw StopBlockCalledException();
    }
}

const char *  StopBlockCalledException::what() const noexcept
{
    return "Block \"control_stop\" executed!";
}
