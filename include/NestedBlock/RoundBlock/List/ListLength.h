#include "NestedBlock/RoundBlock/List/List.h"
#include <string>
#include <memory>

class ListLength : public RoundBlock
{
public:
    ListLength(const std::shared_ptr<List> l);
    MultiType getValue() const override;
private:
    const std::shared_ptr<List> list;
};
