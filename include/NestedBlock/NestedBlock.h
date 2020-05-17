#pragma once

#include "Block.h"

class NestedBlock : public Block
{
public:
    virtual std::string getValue() const=0;
};
