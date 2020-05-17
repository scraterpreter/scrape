#pragma once

#include <string>
#include <NestedBlock/NestedBlock.h>

class SharpBlock : public NestedBlock
{
public:
    virtual bool getBool() const=0;
};
