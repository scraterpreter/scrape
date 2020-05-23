#include "NestedBlock/RoundBlock/List/List.h"
#include <string>
#include <memory>

class ListGetItem : public RoundBlock
{
public:
    ListGetItem(const std::shared_ptr<List> l,
        const std::shared_ptr<NestedBlock> i);
    std::string getValue() const override;
private:
    const std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> index;
};
