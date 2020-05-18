#pragma once

#include <string>
#include "NestedBlock/SharpBlock/SharpBlock.h"

class LogicalNot : public SharpBlock
{
public:
    bool getBool() const override;
    //std::string getValue() const override;
    LogicalNot(const SharpBlock& v);
private:
    const SharpBlock &val;
};
