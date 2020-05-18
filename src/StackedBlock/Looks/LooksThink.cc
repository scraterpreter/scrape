#include <iostream>
#include <string>
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/Looks/LooksThink.h"

void LooksThink::exec() const
{
    std::cout << val.getValue();
}
LooksThink::LooksThink(const NestedBlock& v) : val(v) {}
