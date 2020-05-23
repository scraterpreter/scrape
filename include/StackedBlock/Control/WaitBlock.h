#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class NestedBlock;

class WaitBlock : public StackedBlock
{
public:
    WaitBlock(const std::shared_ptr<NestedBlock> d);
    void exec() const override;
private:
    const std::shared_ptr<NestedBlock> duration;
};
