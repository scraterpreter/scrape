#include "NestedBlock/RoundBlock/List/ListGetItem.h"
#include <string>

ListGetItem::ListGetItem(const std::shared_ptr<List> l,
    const std::shared_ptr<NestedBlock> i)
    : list(l),index(i) {}

std::string ListGetItem::getValue() const
{
    int i=index->getDouble()-1;
    if(i>=0 && i<(list->length()))
    {
        return list->getIndex(i);
    }
    else
    {
        return "";
    }
}
