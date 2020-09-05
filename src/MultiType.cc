#include "MultiType.h"

MultiType::MultiType(const std::string &s)
{
    stringVar=s;
    type=STRING;
}
std::string MultiType::getString()
{
    if(type!=STRING)
    {
        stringVar=std::to_string(doubleVar);
        type=STRING;
    }
    return stringVar;
}
double MultiType::getDouble()
{
    if(type!=DOUBLE)
    {
        try
        {
            doubleVar=std::stod(stringVar);
        }
        catch(const std::invalid_argument& ia)
        {
            doubleVar=0;
        }
        type=DOUBLE;
    }
    return doubleVar;
}
void MultiType::setString(const std::string &s)
{
    stringVar=s;
    type=STRING;
}
void MultiType::setDouble(const double &d)
{
    doubleVar=d;
    type=DOUBLE;
}
