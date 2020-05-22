#include <memory>
#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "StackedBlock/ListOperation/ListInsertItem.h"
#include "NestedBlock/RoundBlock/List/List.h"

ListInsertItem::ListInsertItem(const std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> i,
    const std::shared_ptr<NestedBlock> val)
    : list(l),index(i),value(val){}

void ListInsertItem::exec() const
{
    int insertIndex=index->getDouble()-1;
    if(insertIndex>=0&&insertIndex<=list->length())
    {
        list->insert(insertIndex,value->getValue());
    }
}
