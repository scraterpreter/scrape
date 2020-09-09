#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "NestedBlock/RoundBlock/Constant.h"

class OperatorsMathOp : public RoundBlock
{
public:
    MultiType getValue() const override;
    OperatorsMathOp(std::shared_ptr<Constant> o, std::shared_ptr<NestedBlock> n);
private:
    std::shared_ptr<Constant> op;
    std::shared_ptr<NestedBlock> num;
};
