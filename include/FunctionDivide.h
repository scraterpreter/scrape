#include <string>
#include "BinaryFunction.h"

class FunctionDivide : public BinaryFunction
{
public:
    std::string getValue() const override;
    using BinaryFunction::BinaryFunction;
};
