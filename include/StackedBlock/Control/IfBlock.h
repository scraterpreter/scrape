#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;
class SharpBlock;

class IfBlock : public StackedBlock
{
public:
    IfBlock(const std::shared_ptr<SharpBlock> cond,const std::shared_ptr<StackOfBlocks> ib);
    void exec() const override;
private:
    const std::shared_ptr<SharpBlock> condition;
    const std::shared_ptr<StackOfBlocks> ifBody;
};
