#pragma once

#include <memory>
#include "NestedBlock/SharpBlock/SharpBlock.h"

class BinaryLogical : public SharpBlock
{
public:
    BinaryLogical(const std::shared_ptr<SharpBlock> l,const std::shared_ptr<SharpBlock> r);
    bool getBool() const override=0;
//    std::string getValue() const;
protected:
    const std::shared_ptr<SharpBlock> left,right;
};
