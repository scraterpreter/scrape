#pragma once

#include <string>
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "MultiType.h"

class Constant : public RoundBlock
{
public:
    MultiType getValue() const override;
    Constant(std::string v);
private:
    MultiType val;
};
