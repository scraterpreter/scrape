#include <string>
#include "BinaryFunction.h"

class FunctionSubtract : public BinaryFunction
{
public:
    std::string getValue() const override;
    using BinaryFunction::BinaryFunction;
};
