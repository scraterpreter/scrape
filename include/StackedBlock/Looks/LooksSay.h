#pragma once

#include <string>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/StackedBlock.h"

class LooksSay : public StackedBlock
{
public:
    void exec() const override;
    LooksSay(const NestedBlock& v);
private:
    const NestedBlock &val;
};
