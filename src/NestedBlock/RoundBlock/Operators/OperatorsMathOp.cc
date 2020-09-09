#include <string>
#include <memory>
#include <cmath>
#include "NestedBlock/RoundBlock/Constant.h"
#include "NestedBlock/RoundBlock/Operators/OperatorsMathOp.h"

namespace
{
    const double RAD = 57.29577951308232;
}

MultiType OperatorsMathOp::getValue() const
{
    double inp = num->getDouble();
    double ans;
    if (op->getString() == "abs") {
        ans = std::abs(inp);
    } else if (op->getString() == "floor") {
        ans = floor(inp);
    } else if (op->getString() == "ceiling") {
        ans = ceil(inp);
    } else if (op->getString() == "sqrt") {
        ans = sqrt(inp);
    } else if (op->getString() == "sin") {
        ans = sin(inp/RAD);
    } else if (op->getString() == "cos") {
        ans = cos(inp/RAD);
    } else if (op->getString() == "tan") {
        ans = tan(inp/RAD);
    } else if (op->getString() == "asin") {
        ans = asin(inp)*RAD;
    } else if (op->getString() == "acos") {
        ans = acos(inp)*RAD;
    } else if (op->getString() == "atan") {
        ans = atan(inp)*RAD;
    } else if (op->getString() == "ln") {
        ans = log(inp);
    } else if (op->getString() == "log") {
        ans = log10(inp);
    } else if (op->getString() == "e ^") {
        ans = exp(inp);
    } else if (op->getString() == "10 ^") {
        ans = pow(10, inp);
    } else {
        ans = inp;
    }
    return std::to_string(ans);
}

OperatorsMathOp::OperatorsMathOp(std::shared_ptr<Constant> o, std::shared_ptr<NestedBlock> n) : op(o), num(n) {}
