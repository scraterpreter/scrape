#pragma once

#include <string>
#include <memory>
#include "NestedBlock/SharpBlock/SharpBlock.h"

class LogicalNot : public SharpBlock
{
public:
    bool getBool() const override;
    //std::string getValue() const override;
    LogicalNot(const std::shared_ptr<SharpBlock> v);
private:
    const std::shared_ptr<SharpBlock> val;
};
