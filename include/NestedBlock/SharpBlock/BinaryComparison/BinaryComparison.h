#pragma once

#include <string>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

class BinaryComparison : public SharpBlock
{
public:
    bool getBool() const override=0;
    std::string getValue() const;
    BinaryComparison(const NestedBlock& l,const NestedBlock& r);
protected:
    const NestedBlock &left, &right;
};
