#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class BinaryFunction : public RoundBlock
{
public:
    MultiType getValue() const override=0;
    BinaryFunction(const std::shared_ptr<NestedBlock> l,const std::shared_ptr<NestedBlock> r);
protected:
    const std::shared_ptr<NestedBlock> left, right;
};
