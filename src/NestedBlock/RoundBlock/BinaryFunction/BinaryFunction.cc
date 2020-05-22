#include <string>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/BinaryFunction.h"

BinaryFunction::BinaryFunction(const std::shared_ptr<NestedBlock> l,
    const std::shared_ptr<NestedBlock> r) : left(l),right(r) {}
