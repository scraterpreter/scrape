#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class OperatorsLetterOf : public RoundBlock
{
public:
    MultiType getValue() const override;
    OperatorsLetterOf(std::shared_ptr<NestedBlock> l, std::shared_ptr<NestedBlock> s);
private:
    std::shared_ptr<NestedBlock> letter;
    std::shared_ptr<NestedBlock> str;
};
