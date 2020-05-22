#include <memory>
#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListReplaceItem: public StackedBlock
{
public:
    ListReplaceItem(std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> i,
        const std::shared_ptr<NestedBlock> val);
    void exec() const override;
private:
    std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> index;
    const std::shared_ptr<NestedBlock> value;
};
