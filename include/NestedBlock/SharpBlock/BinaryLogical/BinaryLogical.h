#include "NestedBlock/SharpBlock/SharpBlock.h"

class BinaryLogical : public SharpBlock
{
public:
    BinaryLogical(const SharpBlock& l,const SharpBlock& r);
    bool getBool() const override=0;
    std::string getValue() const override=0;
protected:
    const SharpBlock &left,&right;
};
