#include "NestedBlock/RoundBlock/List/List.h"
#include <string>

class ListLength : public RoundBlock
{
public:
    ListLength(const List& l);
    std::string getValue() const override;
private:
    const List& list;
};
