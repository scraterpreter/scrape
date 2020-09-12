#include "NestedBlock/RoundBlock/List/ListLength.h"
#include <string>

ListLength::ListLength(const std::shared_ptr<List> l)
    : list(l) {}

MultiType ListLength::getValue() const
{
    return list->length();
}
