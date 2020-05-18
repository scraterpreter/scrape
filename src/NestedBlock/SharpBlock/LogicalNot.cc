#include <string>
#include "NestedBlock/SharpBlock/SharpBlock.h"
#include "NestedBlock/SharpBlock/LogicalNot.h"

LogicalNot::LogicalNot(const SharpBlock& v) : val(v) {}

bool LogicalNot::getBool() const
{
    return !val.getBool();
}
/*
std::string LogicalNot::getValue() const
{
    return std::to_string(getBool() ? 1 : 0);
}*/
