#include "NestedBlock/RoundBlock/List/ListFindItem.h"
#include <string>

ListFindItem::ListFindItem(const std::shared_ptr<List> l,
    const std::shared_ptr<NestedBlock> val)
    : list(l),value(val) {}

MultiType ListFindItem::getValue() const
{
    ListFindResult res=list->find(value->getValue());
    if(res.itemFound)
    {
        return std::to_string(res.index+1);
    }
    else
    {
        return MultiType("0");
    }
}
