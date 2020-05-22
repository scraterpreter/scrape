#include <string>
#include "NestedBlock/SharpBlock/BinaryComparison/BinaryComparison.h"

BinaryComparison::BinaryComparison(const std::shared_ptr<NestedBlock> l,
    const std::shared_ptr<NestedBlock> r) : left(l),right(r) {}
