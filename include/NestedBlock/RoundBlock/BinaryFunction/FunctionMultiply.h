#pragma once

#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/BinaryFunction.h"

class FunctionMultiply : public BinaryFunction
{
public:
    MultiType getValue() const override;
    using BinaryFunction::BinaryFunction;
};
