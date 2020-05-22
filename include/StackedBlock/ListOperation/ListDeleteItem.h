#include <memory>
#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListDeleteItem: public StackedBlock
{
public:
    ListDeleteItem(std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> i);
    void exec() const override;
private:
    std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> index;
};
