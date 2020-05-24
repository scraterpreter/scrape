#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class LengthBlock : public RoundBlock
{
public:
    std::string getValue() const override;
    LengthBlock(std::shared_ptr<NestedBlock> s);
private:
    std::shared_ptr<NestedBlock> str;
};
