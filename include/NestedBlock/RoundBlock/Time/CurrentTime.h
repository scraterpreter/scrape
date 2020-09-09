#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/RoundBlock.h"

class CurrentTime : public RoundBlock
{
public:
    CurrentTime(std::shared_ptr<Constant> opt);
    MultiType getValue() const override;
private:
    std::shared_ptr<Constant> option;
};
