#include "StackedBlock/StackedBlock.h"
#include <memory>

class GlobalTimer;

class ResetTimer : public StackedBlock
{
public:
    ResetTimer(std::shared_ptr<GlobalTimer> gt);
    void exec() const override;
private:
    std::shared_ptr<GlobalTimer> globalTimer;
};
