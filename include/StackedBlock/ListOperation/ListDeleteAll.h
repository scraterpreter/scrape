#include <memory>
#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListDeleteAll : public StackedBlock
{
public:
    ListDeleteAll(std::shared_ptr<List> l);
    void exec() const override;
private:
    std::shared_ptr<List> list;
};
