#include <iostream>
#include <string>
#include <memory>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksSay.h"

void LooksSay::exec() const
{
    std::cout << val->getValue() << '\n';
}
LooksSay::LooksSay(const std::shared_ptr<NestedBlock> v) : val(v) {}
