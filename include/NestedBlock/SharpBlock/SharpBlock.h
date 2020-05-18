#pragma once

#include <string>
#include <NestedBlock/NestedBlock.h>

class SharpBlock : public NestedBlock
{
public:
    virtual bool getBool() const=0;
    std::string getValue() const override;
    double getDouble() const override;
};
