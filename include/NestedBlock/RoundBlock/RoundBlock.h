#pragma once

#include <string>
#include "NestedBlock/NestedBlock.h"

class MultiType;

class RoundBlock : public NestedBlock
{
public:
    virtual MultiType getValue() const=0;
};
