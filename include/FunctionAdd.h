#include <string>
#include "BinaryFunction.h"

class FunctionAdd : public BinaryFunction
{
public:
    std::string getValue() const override;
    using BinaryFunction::BinaryFunction;
};
