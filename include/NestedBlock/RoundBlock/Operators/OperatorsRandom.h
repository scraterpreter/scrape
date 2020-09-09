#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class OperatorsRandom : public RoundBlock
{
public:
    MultiType getValue() const override;
    OperatorsRandom(std::shared_ptr<NestedBlock> lb, std::shared_ptr<NestedBlock> ub);
private:
    std::shared_ptr<NestedBlock> lower;
    std::shared_ptr<NestedBlock> upper;
};
