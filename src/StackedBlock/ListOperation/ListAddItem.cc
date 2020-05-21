#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "StackedBlock/ListOperation/ListAddItem.h"

ListAddItem::ListAddItem(List& l,const NestedBlock& val)
    : list(l),value(val){}
void ListAddItem::exec() const
{
    list.add(value.getValue());
}
