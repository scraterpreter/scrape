#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/List.h"
#include "StackedBlock/ListOperation/ListReplaceItem.h"

ListReplaceItem::ListReplaceItem(List& l,const NestedBlock& i,
    const NestedBlock& val)
    : list(l),index(i),value(val){}

void ListReplaceItem::exec() const
{
    int replaceIndex=index.getDouble()-1;
    if(replaceIndex>=0&&replaceIndex<list.length())
    {
        list.replace(replaceIndex,value.getValue());
    }
}
