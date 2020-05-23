#include <algorithm>
#include <vector>
#include <string>
#include "NestedBlock/RoundBlock/List/List.h"

std::string List::getValue() const
{
    std::string output;
    for (std::string i:val) {
        output.append(i + " ");
    }
    return output.substr(0, output.length()-1);
}

std::vector<std::string> List::getVector() const
{
    return val;
}

std::string List::getIndex(int index) const
{
    return val[index];
}

void List::setVector(std::vector<std::string> v)
{
    val = v;
}

void List::add(std::string v)
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

void List::insert(int index, std::string v)
{
    val.insert(val.begin()+index, v);
}

void List::replace(int index, std::string v)
{
    val[index] = v;
}

int List::length() const
{
    return val.size();
}

ListFindResult List::find(std::string v)
{
    std::vector<std::string>::iterator it=std::find(val.begin(),
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

List::List(std::vector<std::string> v) : val(v) {}
List::List(){}
