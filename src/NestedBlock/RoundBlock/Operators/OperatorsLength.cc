#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Operators/OperatorsLength.h"

std::string OperatorsLength::getValue() const
{
    return std::to_string(str->getValue().length());
}

OperatorsLength::OperatorsLength(std::shared_ptr<NestedBlock> s) : str(s) {}
