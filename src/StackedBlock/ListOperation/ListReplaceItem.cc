#include <memory>
#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/ListOperation/ListReplaceItem.h"
#include "NestedBlock/RoundBlock/List/List.h"

ListReplaceItem::ListReplaceItem(std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> i,
    const std::shared_ptr<NestedBlock> val)
    : list(l),index(i),value(val){}

void ListReplaceItem::exec() const
{
    int replaceIndex=index->getDouble()-1;
    if(replaceIndex>=0&&replaceIndex<list->length())
    {
        list->replace(replaceIndex,value->getValue());
    }
}
