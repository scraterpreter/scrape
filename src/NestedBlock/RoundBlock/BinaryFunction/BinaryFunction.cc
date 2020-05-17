#include <string>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/BinaryFunction/BinaryFunction.h"

BinaryFunction::BinaryFunction(const NestedBlock& l,const NestedBlock& r) : left(l),right(r) {}
