#include "NestedBlock/SharpBlock/SharpBlock.h"
#include <memory>

class List;

class ListContainsItem : public SharpBlock
{
public:
    ListContainsItem(const std::shared_ptr<List> l,
        const std::shared_ptr<NestedBlock> val);

    bool getBool() const override;
private:
    const std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> value;
};
