#include <NestedBlock/SharpBlock/SharpBlock.h>
#include <string>

std::string SharpBlock::getString() 
{
    if(getBool()) return "true";
    else return "false";
}

double SharpBlock::getDouble() 
{
    if(getBool()) return 1;
    else return 0;
}

MultiType SharpBlock::getValue() const
{
    if(getBool()) return MultiType("true");
    else return MultiType("false");
}
