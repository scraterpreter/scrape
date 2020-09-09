#pragma once

#include <string>
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "MultiType.h"

class Variable : public RoundBlock
{
public:
    MultiType getValue() const override;
    void setValue(MultiType v);
    Variable(std::string v);
    Variable();
private:
    MultiType val;
};
