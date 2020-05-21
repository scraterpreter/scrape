#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListDeleteItem: public StackedBlock
{
public:
    ListDeleteItem(List& l,const NestedBlock& i);
    void exec() const override;
private:
    List& list;
    const NestedBlock& index;
};
