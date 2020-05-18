#pragma once

#include "Block.h"

class StackedBlock : public Block
{
public:
    virtual void exec() const=0;
};
