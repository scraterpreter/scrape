#pragma once

#include <string>
#include "NestedBlock/RoundBlock/RoundBlock.h"

class BinaryFunction : public RoundBlock
{
public:
    std::string getValue() const override=0;
    BinaryFunction(const RoundBlock& l,const RoundBlock& r);
protected:
    const RoundBlock &left, &right;
};
