#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class OperatorsLength : public RoundBlock
{
public:
    MultiType getValue() const override;
    OperatorsLength(std::shared_ptr<NestedBlock> s);
private:
    std::shared_ptr<NestedBlock> str;
};
