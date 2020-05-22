#include <memory>
#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListAddItem : public StackedBlock
{
public:
    ListAddItem(std::shared_ptr<List> l,const std::shared_ptr<NestedBlock> val);
    void exec() const override;
private:
    std::shared_ptr<List> list;
    const std::shared_ptr<NestedBlock> value;
};
