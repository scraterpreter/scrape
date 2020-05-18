#include "NestedBlock/RoundBlock/RoundBlock.h"
#include <string>
#include <stdexcept>

double RoundBlock::getDouble() const
{
    try
    {
        return std::stod(getValue());
    }
    catch(const std::invalid_argument& ia)
    {
        return 0;
    }
}
