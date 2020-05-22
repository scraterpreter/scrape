#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class RepeatUntilBlock : public StackedBlock
{
public:
    RepeatUntilBlock(const std::shared_ptr<SharpBlock> cond,const std::shared_ptr<StackOfBlocks> lb);
    void exec() const override;
private:
    const std::shared_ptr<SharpBlock> condition;
    const std::shared_ptr<StackOfBlocks> loopBody;
};
