#include "NestedBlock/NestedBlock.h"
#include "NestedBlock/SharpBlock/OperatorsContains.h"
#include <string>

OperatorsContains::OperatorsContains(const std::shared_ptr<NestedBlock> s1,
    const std::shared_ptr<NestedBlock> s2) : str1(s1),str2(s2) {}

bool OperatorsContains::getBool() const
{
    if (str1->getString().find(str2->getString()) != std::string::npos) {
        return true;
    } else {
        return false;
    }
}
