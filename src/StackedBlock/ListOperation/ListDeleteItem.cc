#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/List.h"
#include "StackedBlock/ListOperation/ListDeleteItem.h"

ListDeleteItem::ListDeleteItem(List& l,const NestedBlock& i)
    : list(l),index(i){}
void ListDeleteItem::exec() const
{
    int deleteIndex=index.getDouble()-1;
    if(deleteIndex>=0&&deleteIndex<list.length())
    {
        list.remove(deleteIndex);
    }
}
