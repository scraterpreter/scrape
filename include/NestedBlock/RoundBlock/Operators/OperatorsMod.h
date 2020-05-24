#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class OperatorsMod : public RoundBlock
{
public:
    std::string getValue() const override;
    OperatorsMod(std::shared_ptr<NestedBlock> n1, std::shared_ptr<NestedBlock> n2);
private:
    std::shared_ptr<NestedBlock> num1;
    std::shared_ptr<NestedBlock> num2;
};
