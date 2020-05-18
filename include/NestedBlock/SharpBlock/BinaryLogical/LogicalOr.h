#pragma once

#include <string>
#include "NestedBlock/SharpBlock/BinaryLogical/BinaryLogical.h"

class LogicalOr : public BinaryLogical
{
public:
    bool getBool() const override;
//    using BinaryLogical::getValue;
    using BinaryLogical::BinaryLogical;
};
