#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class NestedBlock;

class RepeatBlock : public StackedBlock
{
public:
    RepeatBlock(const std::shared_ptr<NestedBlock> t,const std::shared_ptr<StackOfBlocks> lb);
    void exec() const override;
private:
    const std::shared_ptr<NestedBlock> times;
    const std::shared_ptr<StackOfBlocks> loopBody;
};
