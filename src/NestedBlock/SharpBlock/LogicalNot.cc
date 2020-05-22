#include <string>
#include "NestedBlock/SharpBlock/SharpBlock.h"
#include "NestedBlock/SharpBlock/LogicalNot.h"

LogicalNot::LogicalNot(const std::shared_ptr<SharpBlock> v) : val(v) {}

bool LogicalNot::getBool() const
{
    return !val->getBool();
}
