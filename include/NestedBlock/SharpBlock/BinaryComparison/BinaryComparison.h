#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"

class BinaryComparison : public SharpBlock
{
public:
    bool getBool() const override=0;
//    std::string getValue() const;
    BinaryComparison(const std::shared_ptr<NestedBlock> l,const std::shared_ptr<NestedBlock> r);
protected:
    const std::shared_ptr<NestedBlock> left, right;
};
