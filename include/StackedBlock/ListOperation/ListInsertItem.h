#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListInsertItem: public StackedBlock
{
public:
    ListInsertItem(List& l,const NestedBlock& i,
        const NestedBlock& val);
    void exec() const override;
private:
    List& list;
    const NestedBlock& index;
    const NestedBlock& value;
};
