#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListAddItem : public StackedBlock
{
public:
    ListAddItem(List& l,const NestedBlock& val);
    void exec() const override;
private:
    List& list;
    const NestedBlock& value;
};
