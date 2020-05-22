#include <memory>
#include "StackedBlock/StackedBlock.h"
#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/RoundBlock/List/List.h"
#include "StackedBlock/ListOperation/ListAddItem.h"

ListAddItem::ListAddItem(std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> val)
    : list(l),value(val){}
void ListAddItem::exec() const
{
    list->add(value->getValue());
}
