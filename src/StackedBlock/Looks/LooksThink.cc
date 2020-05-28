#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksThink.h"

void LooksThink::exec() const
{
    if (std::regex_match (val->getValue(), std::regex("(\\d*)\\.?(\\d*)"))) {
        std::cout << std::stod(val->getValue());
    } else {
        std::cout << val->getValue();
    }
}
LooksThink::LooksThink(const std::shared_ptr<NestedBlock> v) : val(v) {}
