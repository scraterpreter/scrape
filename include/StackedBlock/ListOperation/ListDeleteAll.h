#include "StackedBlock/StackedBlock.h"

class List;
class NestedBlock;

class ListDeleteAll : public StackedBlock
{
public:
    ListDeleteAll(List& l);
    void exec() const override;
private:
    List& list;
};
