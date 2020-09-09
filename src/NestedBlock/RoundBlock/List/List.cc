#include <algorithm>
#include <vector>
#include <string>
#include "NestedBlock/RoundBlock/List/List.h"

MultiType List::getValue() const
{
    std::string output;
    for (MultiType i : val) {
        output.append(i.getString() + " ");
    }
    return output.substr(0, output.length()-1);
}
/*
MultiType<std::string> List::getVector() const
{
    return val;
}
*/
MultiType List::getIndex(int index) const
{
    return val[index];
}
/*
void List::setVector(std::vector<MultiType> v)
{
    val = v;
}
*/
void List::add(MultiType v)
{
    val.push_back(v);
}

void List::remove(int index)
{
    val.erase(val.begin()+index);
}

void List::clear()
{
    val.clear();
}

void List::insert(int index, MultiType v)
{
    val.insert(val.begin()+index, v);
}

void List::replace(int index, MultiType v)
{
    val[index] = v;
}

int List::length() const
{
    return val.size();
}

ListFindResult List::find(MultiType v)
{
    std::vector<MultiType>::iterator it=std::find(val.begin(),
        val.end(),v);
    ListFindResult res;
    if(it==val.end())
    {
        res.itemFound=false;
        res.index=0x3f3f3f3f;
    }
    else
    {
        res.itemFound=true;
        res.index=it-val.begin();
    }
    return res;
}

List::List(std::vector<std::string> v) 
{
    val.assign(v.begin(),v.end()); // vector::assign converts string to MultiType
}
List::List(){}
