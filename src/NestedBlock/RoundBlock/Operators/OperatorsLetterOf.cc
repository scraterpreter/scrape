#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsLetterOf.h"

std::string OperatorsLetterOf::getValue() const
{
    int index = (int)(letter->getDouble())-1;
    return str->getValue().substr(index, 1);
}

OperatorsLetterOf::OperatorsLetterOf(std::shared_ptr<NestedBlock> l, std::shared_ptr<NestedBlock> s) : letter(l), str(s) {}
