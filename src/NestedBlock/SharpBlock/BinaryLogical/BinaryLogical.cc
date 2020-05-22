#include "NestedBlock/SharpBlock/BinaryLogical/BinaryLogical.h"

BinaryLogical::BinaryLogical(const std::shared_ptr<SharpBlock> l,
    const std::shared_ptr<SharpBlock> r) : left(l),right(r) {}
