#pragma once

#include <string>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/StackedBlock.h"

class LooksThink : public StackedBlock
{
public:
    void exec() const override;
    LooksThink(const NestedBlock& v);
private:
    const NestedBlock &val;
};
