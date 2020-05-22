#pragma once

#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/RoundBlock.h"

class Constant : public RoundBlock
{
public:
    std::string getValue() const override;
    Constant(std::shared_ptr<std::string> v);
private:
    const std::shared_ptr<std::string> val;
};
