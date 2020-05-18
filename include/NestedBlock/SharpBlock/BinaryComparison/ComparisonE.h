#pragma once

#include <string>
#include "NestedBlock/SharpBlock/BinaryComparison/BinaryComparison.h"

class ComparisonE : public BinaryComparison
{
public:
    bool getBool() const override;
    //using BinaryComparison::getValue;
    using BinaryComparison::BinaryComparison;
};
