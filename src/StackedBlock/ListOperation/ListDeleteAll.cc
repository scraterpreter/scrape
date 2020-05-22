#include <memory>
#include "StackedBlock/ListOperation/ListDeleteAll.h"
#include "NestedBlock/RoundBlock/List/List.h"

ListDeleteAll::ListDeleteAll(std::shared_ptr<List> l)
    : list(l){}
void ListDeleteAll::exec() const
{
    list->clear();
}
