#include <string>
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalAnd.h"

bool LogicalAnd::getBool() const
{
    return left->getBool() && right->getBool();
}
