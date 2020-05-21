#include "StackedBlock/ListOperation/ListDeleteAll.h"
#include "NestedBlock/RoundBlock/List/List.h"

ListDeleteAll::ListDeleteAll(List& l)
    : list(l){}
void ListDeleteAll::exec() const
{
    list.clear();
}
