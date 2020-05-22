#pragma once

#include <string>
#include <memory>
#include "NestedBlock/RoundBlock/RoundBlock.h"

class Variable : public RoundBlock
{
public:
    std::string getValue() const override;
    void setValue(std::string v);
    Variable(std::shared_ptr<std::string> v);
    Variable();
private:
    std::shared_ptr<std::string> val;
};
