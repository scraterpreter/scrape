#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/StackedBlock.h"

class LooksThink : public StackedBlock
{
public:
    void exec() const override;
    LooksThink(const std::shared_ptr<NestedBlock> v);
private:
    const std::shared_ptr<NestedBlock> val;
};
