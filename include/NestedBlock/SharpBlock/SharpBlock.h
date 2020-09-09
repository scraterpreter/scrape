#pragma once

#include <string>
#include <NestedBlock/NestedBlock.h>

class SharpBlock : public NestedBlock
{
public:
    MultiType getValue() const override;
    virtual bool getBool() const=0;
    std::string getString() override;
    double getDouble() override;
};
