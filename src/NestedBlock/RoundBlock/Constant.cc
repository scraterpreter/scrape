#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Constant.h"

std::string Constant::getValue() const
{
    return *val.get();
}
Constant::Constant(std::shared_ptr<std::string> v) : val(v) {}
