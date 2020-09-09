#include "NestedBlock/RoundBlock/RoundBlock.h"
#include <memory>

class GlobalTimer;

class TimerBlock : public RoundBlock
{
public:
    MultiType getValue() const override;
    TimerBlock(std::shared_ptr<GlobalTimer> gt);
private:
    std::shared_ptr<GlobalTimer> globalTimer;
};
