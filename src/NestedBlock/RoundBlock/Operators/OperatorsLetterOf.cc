#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsLetterOf.h"

MultiType OperatorsLetterOf::getValue() const
{
    int index = (int)(letter->getDouble())-1;
    return str->getString().substr(index, 1);
}

OperatorsLetterOf::OperatorsLetterOf(std::shared_ptr<NestedBlock> l, std::shared_ptr<NestedBlock> s) : letter(l), str(s) {}
