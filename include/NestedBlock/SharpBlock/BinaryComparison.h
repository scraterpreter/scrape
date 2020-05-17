#pragma once

#include <string>
#include "NestedBlock/SharpBlock/SharpBlock.h"

class BinaryComparison : public SharpBlock
{
public:
    //std::string getValue() const override=0;
    BinaryComparison(const RoundBlock& l,const RoundBlock& r);
protected:
    const RoundBlock &left, &right;
};
