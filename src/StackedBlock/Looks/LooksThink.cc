#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksThink.h"

void LooksThink::exec() const
{
    std::cout << val->getValue();
}
LooksThink::LooksThink(const std::shared_ptr<NestedBlock> v) : val(v) {}
