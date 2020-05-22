#include <string>
#include "NestedBlock/SharpBlock/BinaryLogical/LogicalOr.h"

bool LogicalOr::getBool() const
{
    return left->getBool() || right->getBool();
}
