#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class WaitUntilBlock : public StackedBlock
{
public:
    WaitUntilBlock(const std::shared_ptr<SharpBlock> cond);
    void exec() const override;
private:
    const std::shared_ptr<SharpBlock> condition;
};
