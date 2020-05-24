#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class JoinBlock : public RoundBlock
{
public:
    std::string getValue() const override;
    JoinBlock(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> rb);
private:
    std::shared_ptr<NestedBlock> left;
    std::shared_ptr<NestedBlock> right;
};
