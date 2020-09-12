#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsLength.h"

MultiType OperatorsLength::getValue() const
{
    return str->getString().length();
}

OperatorsLength::OperatorsLength(std::shared_ptr<NestedBlock> s) : str(s) {}
