#pragma once

#include <string>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class BinaryFunction : public RoundBlock
{
public:
    std::string getValue() const override=0;
    BinaryFunction(const NestedBlock& l,const NestedBlock& r);
protected:
    const NestedBlock &left, &right;
};
