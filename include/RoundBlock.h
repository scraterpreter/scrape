#pragma once

#include <string>
#include "NestedBlock.h"

class RoundBlock : public NestedBlock
{
public:
    virtual std::string getValue() const=0;
};
