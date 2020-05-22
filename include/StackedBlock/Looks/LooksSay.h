#pragma once

#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/StackedBlock.h"

class LooksSay : public StackedBlock
{
public:
    void exec() const override;
    LooksSay(const std::shared_ptr<NestedBlock> v);
private:
    const std::shared_ptr<NestedBlock> val;
};
