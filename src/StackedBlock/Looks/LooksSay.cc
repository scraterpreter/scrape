#include <iostream>
#include <string>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksSay.h"

void LooksSay::exec() const
{
    std::cout << val.getValue() << '\n';
}
LooksSay::LooksSay(const NestedBlock& v) : val(v) {}
