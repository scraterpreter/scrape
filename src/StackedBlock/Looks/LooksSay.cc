#include <iostream>
#include <string>
#include <memory>
#include <regex>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksSay.h"

void LooksSay::exec() const
{
    if (std::regex_match (val->getValue(), std::regex("(\\d+)\\.?(\\d*)"))) {
        std::cout << std::stod(val->getValue()) << '\n';
    } else {
        std::cout << val->getValue() << '\n';
    }
}
LooksSay::LooksSay(const std::shared_ptr<NestedBlock> v) : val(v) {}
