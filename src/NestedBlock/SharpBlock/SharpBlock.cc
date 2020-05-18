#include <NestedBlock/SharpBlock/SharpBlock.h>
#include <string>

std::string SharpBlock::getValue() const
{
    if(getBool()) return "true";
    else return "false";
}

double SharpBlock::getDouble() const
{
    if(getBool()) return 1;
    else return 0;
}
