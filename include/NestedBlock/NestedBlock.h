#pragma once

#include "Block.h"
#include <string>

class NestedBlock : public Block
{
public:
    virtual std::string getValue() const=0;
    virtual double getDouble() const=0;
};
