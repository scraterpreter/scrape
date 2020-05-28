#pragma once

#include "StackedBlock/StackedBlock.h"
#include <memory>

class Constant;

class StopBlock : public StackedBlock
{
public:
    StopBlock(std::shared_ptr<Constant> opt);
    void exec() const override;
private:
    std::shared_ptr<Constant> option;
};

class StopBlockCalledException : public std::exception
{
    const char *  what() const noexcept override;
};
