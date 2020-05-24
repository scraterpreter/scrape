#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class OperatorsRound : public RoundBlock
{
public:
    std::string getValue() const override;
    OperatorsRound(std::shared_ptr<NestedBlock> n);
private:
    std::shared_ptr<NestedBlock> num;
};
