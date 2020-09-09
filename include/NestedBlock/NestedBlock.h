#pragma once

#include "Block.h"
#include "MultiType.h"

class MultiType;

class NestedBlock : public Block
{
public:
    virtual MultiType getValue() const=0;
    virtual double getDouble();
    virtual std::string getString();
};
