#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/SharpBlock/SharpBlock.h"
#include <memory>
#include <string>

class OperatorsContains : public SharpBlock
{
public:
    OperatorsContains(const std::shared_ptr<NestedBlock> s1,
        const std::shared_ptr<NestedBlock> s2);

    bool getBool() const override;
private:
    const std::shared_ptr<NestedBlock> str1;
    const std::shared_ptr<NestedBlock> str2;
};
