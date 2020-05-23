#include "NestedBlock/RoundBlock/List/List.h"
#include <string>
#include <memory>

class ListFindItem : public RoundBlock
{
public:
    ListFindItem(const std::shared_ptr<List> l,
        const std::shared_ptr<NestedBlock> val);
    std::string getValue() const override;
private:
    const std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> value;
};
