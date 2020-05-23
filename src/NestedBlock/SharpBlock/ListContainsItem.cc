#include "NestedBlock/SharpBlock/ListContainsItem.h"
#include "NestedBlock/RoundBlock/List/List.h"

ListContainsItem::ListContainsItem(const std::shared_ptr<List> l,
    const std::shared_ptr<NestedBlock> val) : list(l),value(val) {}

bool ListContainsItem::getBool() const
{
    return list->find(value->getValue()).itemFound;
}
