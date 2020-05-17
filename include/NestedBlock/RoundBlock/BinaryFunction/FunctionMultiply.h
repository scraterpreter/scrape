#include <string>
#include "NestedBlock/RoundBlock/BinaryFunction/BinaryFunction.h"

class FunctionMultiply : public BinaryFunction
{
public:
    std::string getValue() const override;
    using BinaryFunction::BinaryFunction;
};
