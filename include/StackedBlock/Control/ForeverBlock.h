#include <memory>
#include "StackedBlock/StackedBlock.h"

class StackOfBlocks;

class ForeverBlock : public StackedBlock
{
public:
    ForeverBlock(const std::shared_ptr<StackOfBlocks> lb);
    void exec() const override;
private:
    const std::shared_ptr<StackOfBlocks> loopBody;
};
