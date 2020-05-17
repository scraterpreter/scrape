#pragma once

#include <string>
#include "NestedBlock/SharpBlock/BinaryLogical/BinaryLogical.h"

class LogicalAnd : public BinaryLogical
{
public:
    bool getBool() const override;
    using BinaryLogical::getValue;
    using BinaryLogical::BinaryLogical;
};
