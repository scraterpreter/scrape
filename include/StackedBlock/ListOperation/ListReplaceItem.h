#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListReplaceItem: public StackedBlock
{
public:
    ListReplaceItem(List& l,const NestedBlock& i,
        const NestedBlock& val);
    void exec() const override;
private:
    List& list;
    const NestedBlock& index;
    const NestedBlock& value;
};
